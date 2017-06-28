/*
** action_connect.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
**
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
**
** Started on  Mon Jun 19 19:38:17 2017 Mathis Guilbon
** Last update Wed Jun 28 15:18:56 2017 Mathis Guilbon
*/

#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "server.h"

void		get_real_pos_from(t_data *data, t_position *pos)
{
  if (pos->y >= (int)data->height)
    pos->y -= data->height;
  else if (pos->y < 0)
    pos->y += data->height;
  if (pos->x >= (int)data->width)
    pos->x -= data->width;
  else if (pos->x < 0)
    pos->x += data->width;
}

bool		action_connect_nbr(t_data *data, t_player *player, char *prm)
{
  char 		buff[8];
  int		i;

  (void)prm;
  i = -1;
  while (++i < (int)data->nbr_teams &&
	 strcmp(data->team_list[i]->name, player->team) != 0);
  if (i < (int)data->nbr_teams)
    {
      snprintf(buff, 8, "%d\n", data->team_list[i]->free_slots);
      return (socket_write(player->fd, buff) != -1);
    }
  return (false);
}

static void	add_egg_to_list(t_data *data, t_egg *last)
{
  t_egg		*tmp;

  tmp = data->eggs;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (!tmp)
    data->eggs = last;
  else
    tmp->next = last;
}

bool			action_fork(t_data *data, t_player *player, UNUSED char *prm)
{
  t_egg			*last;
  int			i;
  struct timeval	tv;

  if (socket_write(player->fd, "ok\n") == -1 ||
      !(last = malloc(sizeof(t_egg))) ||
      !(last->pos = malloc(sizeof(t_position))) ||
      !(last->team = malloc(strlen(player->team) + 1)))
    return (false);
  last->id = data->eid;
  ++data->eid;
  last->player_id = player->id;
  bzero(last->team, strlen(player->team) + 1);
  i = -1;
  while (++i < (int)strlen(player->team))
    last->team[i] = player->team[i];
  last->pos->x = player->pos->x;
  last->pos->y = player->pos->y;
  last->ready = 0;
  last->next = NULL;
  gettimeofday(&tv, NULL);
  last->timer = (tv.tv_sec + (600 / data->freq)) * 1000 + tv.tv_usec / 1000;
  add_egg_to_list(data, last);
  return (true);
}
