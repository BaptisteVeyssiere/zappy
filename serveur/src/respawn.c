/*
** respawn.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 28 15:49:51 2017 Baptiste Veyssiere
** Last update Fri Jun 30 23:02:13 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "server.h"

static int	bct_tile(t_data *data, int x, int y)
{
  char		buff[50];

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
               data->map[y][x].item[FOOD],
               data->map[y][x].item[LINEMATE],
               data->map[y][x].item[DERAUMERE],
               data->map[y][x].item[SIBUR],
               data->map[y][x].item[MENDIANE],
               data->map[y][x].item[PHIRAS],
               data->map[y][x].item[THYSTAME]) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}

int	respawn(t_data *data, int type)
{
  int	x;
  int	y;
  int	safe_x;
  int	safe_y;

  x = rand() % data->width;
  y = rand() % data->height;
  safe_x = x;
  safe_y = y;
  while (data->map[y][x].players > 0)
    {
      ++x;
      if (x == (int)data->width)
	{
	  x = 0;
	  ++y;
	  if (y == (int)data->height)
	    y = 0;
	}
      if (x == safe_x && y == safe_y)
	return (0);
    }
  ++(data->map[y][x].item[type]);
  return (bct_tile(data, x, y));
}
