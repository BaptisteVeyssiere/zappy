/*
** graphic_command.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Mon Jun 26 17:12:34 2017 Baptiste Veyssiere
** Last update Sat Jul  1 01:24:24 2017 Baptiste Veyssiere
*/

#include <strings.h>
#include <stdio.h>
#include "server.h"

int	tna(t_data *data)
{
  char	buff[50];
  int	i;

  if (data->network->graphic_fd < 2 || data->team_list == NULL)
    return (0);
  i = -1;
  while (data->team_list[++i])
    {
      bzero(buff, 50);
      if (snprintf(buff, 50, "tna %s\n", data->team_list[i]->name) < 0 ||
	  socket_write(data->network->graphic_fd, buff) == -1)
	return (-1);
    }
  return (0);
}

int		bct(t_data *data)
{
  char		buff[100];
  int		x;
  unsigned int	y;

  if (data->network->graphic_fd < 2)
    return (0);
  y = -1;
  while (++y < data->height && (x = -1) == -1)
    while (++x < (int)data->width)
      {
	bzero(buff, 100);
	if (snprintf(buff, 100, "bct %d %d %d %d %d %d %d %d %d\n",
		     x, y, data->map[y][x].item[FOOD],
		     data->map[y][x].item[LINEMATE],
		     data->map[y][x].item[DERAUMERE],
		     data->map[y][x].item[SIBUR],
		     data->map[y][x].item[MENDIANE],
		     data->map[y][x].item[PHIRAS],
		     data->map[y][x].item[THYSTAME]) < 0 ||
	    socket_write(data->network->graphic_fd, buff) == -1)
	  return (-1);
      }
  return (0);
}

int	sgt(t_data *data)
{
  char	buff[50];

  if (data->network->graphic_fd < 2)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "sgt %d\n", data->freq) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}

int	msz(t_data *data)
{
  char	buff[50];

  if (data->network->graphic_fd < 2)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "msz %d %d\n", data->width, data->height) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}

int	pdi(t_data *data, t_player *player)
{
  char	buff[50];

  if (data->network->graphic_fd < 2)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "pdi %d\n", player->id) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}
