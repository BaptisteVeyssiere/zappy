/*
** add_player.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Jun 25 04:33:42 2017 Baptiste Veyssiere
** Last update Mon Jun 26 14:57:50 2017 Baptiste Veyssiere
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

static void	init_player(t_player *last, char *team, t_position pos, int fd)
{
  last->inventory->food = 9;
  last->inventory->linemate = 0;
  last->inventory->deraumere = 0;
  last->inventory->sibur = 0;
  last->inventory->mendiane = 0;
  last->inventory->phiras = 0;
  last->inventory->thystame = 0;
  last->inventory->players = 0;
  last->team = team;
  *(last->pos) = pos;
  last->fd = fd;
  last->sightline = 1;
  last->direction = rand() % 4;
  last->level = 1;
  last->life = 126;
  last->next = NULL;
  last->action = NULL;
}

static void	add_player_to_list(t_data *data, t_player *last)
{
  t_player	*root;

  root = data->players_root;
  while (root && root->next)
    root = root->next;
  if (root == NULL)
    data->players_root = last;
  else
    root->next = last;
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

  tmp = data->eggs;
  pos.x = rand() % data->width;
  pos.y = rand() % data->height;
  while (tmp)
    if (strcmp(tmp->team, team) == 0)
      {
	pos = *(tmp->pos);
	free_egg(data, tmp);
	tmp = NULL;
      }
    else
      tmp = tmp->next;
  if (!(last = malloc(sizeof(t_player))) ||
      !(last->inventory = malloc(sizeof(t_items))) ||
      !(last->pos = malloc(sizeof(t_position))))
    return (write_error(__FILE__, __func__, __LINE__, -1));
  init_player(last, team, pos, fd);
  last->ringbuffer = ringbuffer;
  add_player_to_list(data, last);
  return (0);
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
