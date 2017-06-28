/*
** add_player.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Jun 25 04:33:42 2017 Baptiste Veyssiere
** Last update Wed Jun 28 18:27:53 2017 Baptiste Veyssiere
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "server.h"

static void		init_player(t_player *last, char *team,
				    t_position pos, int fd)
{
  int			i;
  struct timeval	tv;

  i = -1;
  gettimeofday(&tv, NULL);
  while (++i < ITEMNBR)
    {
      last->inventory->item[i] = 0;
      if (i == FOOD)
	last->inventory->item[i] = 9;
    }
  last->team = team;
  *(last->pos) = pos;
  last->fd = fd;
  last->direction = (rand() % 4) + 1;
  last->level = 1;
  last->life = 126;
  last->next = NULL;
  last->action = NULL;
  last->life = tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

static void	add_player_to_list(t_data *data, t_player *last,
				   char is_egg, t_ringbuffer *ringbuffer)
{
  t_player	*root;

  last->eggborn = is_egg;
  last->ringbuffer = ringbuffer;
  last->id = data->pid;
  ++data->pid;
  root = data->players_root;
  while (root && root->next)
    root = root->next;
  if (root == NULL)
    data->players_root = last;
  else
    root->next = last;
  ++data->map[last->pos->y][last->pos->x].players;
}

static void	free_egg(t_data	*data, t_egg *elem)
{
  t_egg	*tmp;
  t_egg	*prev;

  tmp = data->eggs;
  prev = NULL;
  free(elem->team);
  free(elem->pos);
  while (tmp)
    {
      if (tmp == elem)
	{
	  if (prev == NULL)
	    data->eggs = data->eggs->next;
	  else
	    prev->next = tmp->next;
	  free(elem);
	  return ;
	}
      prev = tmp;
      tmp = tmp->next;
    }
}

static int	add_player(t_data *data, int fd,
			   char *team, t_ringbuffer *ringbuffer)
{
  t_egg		*tmp;
  t_position	pos;
  t_player	*last;
  char		is_egg;

  tmp = data->eggs;
  pos.x = rand() % data->width;
  pos.y = rand() % data->height;
  is_egg = 0;
  while (tmp)
    if (strcmp(tmp->team, team) == 0 && tmp->ready && (is_egg = 1) == 1)
      {
	pos = *(tmp->pos);
	free_egg(data, tmp);
	tmp = NULL;
      }
    else
      tmp = tmp->next;
  if (!(last = malloc(sizeof(t_player))) ||
      (last->inventory = malloc(sizeof(t_items))) == NULL ||
      (last->pos = malloc(sizeof(t_position))) == NULL)
    return (write_error(__FILE__, __func__, __LINE__, -1));
  init_player(last, team, pos, fd);
  add_player_to_list(data, last, is_egg, ringbuffer);
  return (pnw(last, data));
}

int	try_add_player(t_data *data, int fd, char *team, t_ringbuffer *ringbuffer)
{
  int	i;
  int	slot;

  i = -1;
  while (data->team_list[++i])
    if (strcmp(data->team_list[i]->name, team) == 0)
      {
        if ((slot = data->team_list[i]->free_slots) < 1)
	  {
	    if (socket_write(fd, "ko\n") == -1)
	      return (-1);
	    return (0);
	  }
        else if (add_player(data, fd, team, ringbuffer) == -1 ||
		 send_basic_info(fd, slot - 1, data->width, data->height) == -1)
          return (-1);
        --data->team_list[i]->free_slots;
        return (1);
      }
  if (socket_write(fd, "ko\n") == -1)
    return (-1);
  return (0);
}
