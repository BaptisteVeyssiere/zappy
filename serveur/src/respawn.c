/*
** respawn.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 28 15:49:51 2017 Baptiste Veyssiere
** Last update Sun Jul  2 18:25:48 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "server.h"

static int	bct_tile(t_data *data, int x, int y)
{
  char		buff[50];
  int		ret;

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
      (ret = socket_write(data->network->graphic_fd, buff)) == -1)
    return (-1);
  if (ret == -2)
    return (init_graphic_fd(data));
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

int		add_to_ilist(t_player *player, t_player *link)
{
  t_incantation	*last;
  t_incantation	*tmp;

  if (!(last = malloc(sizeof(t_incantation))))
    return (-1);
  last->next = NULL;
  last->player = link;
  tmp = player->action->list;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (!tmp)
    player->action->list = last;
  else
    tmp->next = last;
  return (0);
}
