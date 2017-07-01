/*
** graphic_moves.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 28 16:11:58 2017 Baptiste Veyssiere
** Last update Sat Jul  1 15:10:16 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <strings.h>
#include "server.h"

int	ppo(t_player *player, t_data *data)
{
  char	buff[50];

  if (data->network->graphic_fd < 2)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "ppo %d %d %d %d\n", player->id, player->pos->x,
	       player->pos->y, player->direction) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}

int	pnw(t_player *player, t_data *data)
{
  char	buff[100];

  if (data->network->graphic_fd < 2)
    return (0);
  bzero(buff, 100);
  if (snprintf(buff, 100, "pnw %d %d %d %d %d %s\n",
	       player->id, player->pos->x,
	       player->pos->y, player->direction, player->level,
	       player->team) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1 ||
      pin(data, player) == -1)
    return (-1);
  return (0);
}
