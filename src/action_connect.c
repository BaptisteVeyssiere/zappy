/*
** action_connect.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Mon Jun 19 19:38:17 2017 Mathis Guilbon
** Last update Mon Jun 26 14:49:45 2017 Mathis Guilbon
*/

#include "action.h"

bool		eject(t_data *data, t_player *player, t_position *off, char *buff)
{
  t_player	*tmp;

  tmp = data->players_root;
  while (tmp != NULL)
    {
      if (tmp->pos->x == player->pos->x &&
	  tmp->pos->y == player->pos->y &&
	  tmp != player)
	{
	  if (socket_write(tmp->fd, buff) == -1)
	    return (false);
	  --data->map[player->pos->y][player->pos->x].players;
	  ++data->map[off->y][off->x].players;
	  tmp.x = off->x;
	  tmp.y = off->y;
	}
      tmp = tmp->next;
    }
  return (true);
}

bool		action_connect_nbr(t_data *data, t_player *player, char *prm)
{
  char 		buff[8];
  int		i;

  (void)prm;
  i = -1;
  while (++i < data->nbr_teams &&
	 strcmp(data->team_list[i]->name, player->team) != 0);
  if (i < data->nbr_teams)
    {
      snprintf(buff, 8, "%d\n", data->team_list[i]->free_slots);
      return (socket_write(player->fd, buff) != -1);
    }
  return (false);
}

bool		action_fork(t_data *data, t_player *player, char *prm)
{
  return (true);
}

bool		action_broadcast(t_data *data, t_player *player, char *prm)
{
  return (true);
}
