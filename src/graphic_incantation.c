/*
** graphic_incantation.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Fri Jun 30 15:15:53 2017 Baptiste Veyssiere
** Last update Fri Jun 30 15:22:06 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <strings.h>
#include "server.h"

int	pic(t_data *data, t_player *player)
{
  char	buff[20];

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 20);
  if (snprintf(buff, 20, " %d", player->id) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}

int	pic_end(t_data *data)
{
  if (data->network->graphic_fd == -1)
    return (0);
  if (socket_write(data->network->graphic_fd, "\n") == -1)
    return (-1);
  return (0);
}

int	pic_init(t_data *data, t_player *player)
{
  char	buff[50];

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "pic %d %d %d %d", player->pos->x, player->pos->y,
	       player->level, player->id) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}
