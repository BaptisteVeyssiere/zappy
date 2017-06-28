/*
** action_connect.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Mon Jun 19 19:38:17 2017 Mathis Guilbon
** Last update Wed Jun 28 13:13:48 2017 Mathis Guilbon
*/

#include "server.h"

void		get_real_pos_from(t_data *data, t_position *pos)
{
  if (pos->y >= (int)data->height - 1)
    pos->y -= data->height - 1;
  else if (pos->y < 0)
    pos->y += data->height - 1;
  if (pos->x >= (int)data->width - 1)
    pos->x -= data->width - 1;
  else if (pos->x < 0)
    pos->x += data->width - 1;
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

bool		action_fork(t_data *data, t_player *player, char *prm)
{
  (void)prm;
  (void)data;
  (void)player;
  return (true);
}
