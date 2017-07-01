/*
** graphic_egg.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Thu Jun 29 14:10:19 2017 Baptiste Veyssiere
** Last update Sat Jul  1 19:28:19 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <strings.h>
#include "server.h"

int	ebo(t_data *data, t_egg *egg)
{
  char	buff[20];
  int	ret;

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 20);
  if (snprintf(buff, 20, "ebo %d\n", egg->id) < 0 ||
      (ret = socket_write(data->network->graphic_fd, buff)) == -1)
    return (-1);
  if (ret == -2)
    return (init_graphic_fd(data));
  return (0);
}

int	eht(t_data *data, t_egg *egg)
{
  char	buff[50];
  int	ret;

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "eht %d\n", egg->id) < 0 ||
      (ret = socket_write(data->network->graphic_fd, buff)) == -1)
    return (-1);
  if (ret == -2)
    return (init_graphic_fd(data));
  return (0);
}

int	enw(t_data *data, t_egg *egg)
{
  char	buff[50];
  int	ret;

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "enw %d %d %d %d\n", egg->id, egg->player_id,
	       egg->pos->x, egg->pos->y) < 0 ||
      (ret = socket_write(data->network->graphic_fd, buff)) == -1)
    return (-1);
  if (ret == -2)
    return (init_graphic_fd(data));
  return (0);
}
