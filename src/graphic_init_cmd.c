/*
** graphic_init_cmd.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Mon Jun 26 16:45:16 2017 Baptiste Veyssiere
** Last update Fri Jun 30 17:13:37 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <strings.h>
#include "server.h"

int		init_enw(t_data *data)
{
  char		buff[500];
  t_egg		*tmp;

  tmp = data->eggs;
  while (tmp)
    {
      bzero(buff, 500);
      if (snprintf(buff, 500, "enw %d %d %d %d\n", tmp->id, tmp->player_id,
		   tmp->pos->x, tmp->pos->y) < 0 ||
	  socket_write(data->network->graphic_fd, buff) == -1)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}

int		init_pnw(t_data *data)
{
  char		buff[500];
  t_player	*tmp;

  tmp = data->players_root;
  while (tmp)
    {
      bzero(buff, 500);
      if (snprintf(buff, 500, "pnw %d %d %d %d %d %s\n", tmp->id, tmp->pos->x,
		   tmp->pos->y, tmp->direction, tmp->level, tmp->team) < 0 ||
	  socket_write(data->network->graphic_fd, buff) == -1 ||
	  pin(data, tmp) == -1)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}
