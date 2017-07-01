/*
** graphic_actions.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_20
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Fri Jun 30 14:58:22 2017 Baptiste Veyssiere
** Last update Sat Jul  1 19:24:53 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <strings.h>
#include "server.h"

int	pie(t_data *data, unsigned int x, unsigned int y, int result)
{
  char	buff[50];
  int	ret;

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "pie %d %d %d\n", x, y, result) < 0 ||
      (ret = socket_write(data->network->graphic_fd, buff)) == -1)
    return (-1);
  if (ret == -2)
    return (init_graphic_fd(data));
  return (0);
}

int	plv(t_data *data, t_player *player)
{
  char	buff[50];
  int	ret;

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "plv %d %d\n", player->id, player->level) < 0 ||
      (ret = socket_write(data->network->graphic_fd, buff)) == -1)
    return (-1);
  if (ret == -2)
    return (init_graphic_fd(data));
  return (0);
}

int	pbc(t_data *data, t_player *player, char *message)
{
  char	buff[2000];
  int	ret;

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 2000);
  if (snprintf(buff, 2000, "pbc %d %s\n", player->id, message) < 0 ||
      (ret = socket_write(data->network->graphic_fd, buff)) == -1)
    return (-1);
  if (ret == -2)
    return (init_graphic_fd(data));
  return (0);
}

int	pex(t_data *data, t_player *player)
{
  char	buff[20];
  int	ret;

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 20);
  if (snprintf(buff, 20, "pex %d\n", player->id) < 0 ||
      (ret = socket_write(data->network->graphic_fd, buff)) == -1)
    return (-1);
  if (ret == -2)
    return (init_graphic_fd(data));
  return (0);
}
