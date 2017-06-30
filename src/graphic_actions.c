/*
** graphic_actions.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Thu Jun 29 15:39:06 2017 Baptiste Veyssiere
** Last update Fri Jun 30 17:15:01 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <strings.h>
#include "server.h"

int	pin(t_data *data, t_player *player)
{
  char	buff[50];

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "pin %d %d %d %d %d %d %d %d %d %d\n", player->id,
	       player->pos->x, player->pos->y,
	       data->map[player->pos->y][player->pos->x].item[FOOD],
	       data->map[player->pos->y][player->pos->x].item[LINEMATE],
	       data->map[player->pos->y][player->pos->x].item[DERAUMERE],
	       data->map[player->pos->y][player->pos->x].item[SIBUR],
	       data->map[player->pos->y][player->pos->x].item[MENDIANE],
	       data->map[player->pos->y][player->pos->x].item[PHIRAS],
	       data->map[player->pos->y][player->pos->x].item[THYSTAME]) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}

static int	pgt(t_data *data, t_player *player, int type)
{
  char		buff[50];

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "pgt %d %d\n", player->id, type) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}

static int	pdr(t_data *data, t_player *player, int type)
{
  char		buff[50];

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "pdr %d %d\n", player->id, type) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}

int	graphic_take(t_data *data, t_player *player, int type)
{
  char	buff[50];

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 50);
  if (pgt(data, player, type) == -1 ||
      pin(data, player) == -1)
    return (-1);
  if (snprintf(buff, 50, "bct %d %d %d %d %d %d %d %d %d\n", player->pos->x,
	       player->pos->y,
	       data->map[player->pos->y][player->pos->x].item[FOOD],
	       data->map[player->pos->y][player->pos->x].item[LINEMATE],
	       data->map[player->pos->y][player->pos->x].item[DERAUMERE],
	       data->map[player->pos->y][player->pos->x].item[SIBUR],
	       data->map[player->pos->y][player->pos->x].item[MENDIANE],
	       data->map[player->pos->y][player->pos->x].item[PHIRAS],
	       data->map[player->pos->y][player->pos->x].item[THYSTAME]) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}

int	graphic_put(t_data *data, t_player *player, int type)
{
  char	buff[50];

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 50);
  if (pdr(data, player, type) == -1 ||
      pin(data, player) == -1)
    return (-1);
  if (snprintf(buff, 50, "bct %d %d %d %d %d %d %d %d %d\n", player->pos->x,
	       player->pos->y,
	       data->map[player->pos->y][player->pos->x].item[FOOD],
	       data->map[player->pos->y][player->pos->x].item[LINEMATE],
	       data->map[player->pos->y][player->pos->x].item[DERAUMERE],
	       data->map[player->pos->y][player->pos->x].item[SIBUR],
	       data->map[player->pos->y][player->pos->x].item[MENDIANE],
	       data->map[player->pos->y][player->pos->x].item[PHIRAS],
	       data->map[player->pos->y][player->pos->x].item[THYSTAME]) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}
