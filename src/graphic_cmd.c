/*
** graphic_actions.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Fri Jun 30 14:58:22 2017 Baptiste Veyssiere
** Last update Fri Jun 30 15:10:59 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <strings.h>
#include "server.h"

int	pie(t_data *data, unsigned int x, unsigned int y, int result)
{
  char	buff[50];

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "pie %d %d %d\n", x, y, result) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}

int	plv(t_data *data, t_player *player)
{
  char	buff[50];

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 50);
  if (snprintf(buff, 50, "plv %d %d\n", player->id, player->level) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}

int	pbc(t_data *data, t_player *player, char *message)
{
  char	buff[2000];

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 2000);
  if (snprintf(buff, 2000, "pbc %d %s\n", player->id, message) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}

int	pex(t_data *data, t_player *player)
{
  char	buff[20];

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 20);
  if (snprintf(buff, 20, "pex %d\n", player->id) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}
