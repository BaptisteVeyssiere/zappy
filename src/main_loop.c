/*
** main_loop.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 21 15:33:39 2017 Baptiste Veyssiere
** Last update Mon Jun 26 14:23:50 2017 Baptiste Veyssiere
*/

#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include "server.h"

static fd_set	*create_data_set(t_network *network)
{
  fd_set	*set;

  if ((set = malloc(sizeof(fd_set))) == NULL)
    return (NULL);
  FD_ZERO(set);
  FD_SET(network->signal_fd, set);
  FD_SET(network->socket_fd[0], set);
  FD_SET(network->socket_fd[1], set);
  return (set);
}

static int	init_network(t_data *data)
{
  if ((data->network = malloc(sizeof(t_network))) == NULL)
    return (write_error(__FILE__, __func__, __LINE__, -1));
  if ((data->network->socket_fd[0] = bind_port(data->port)) == -1 ||
      (data->network->socket_fd[1] = bind_port(GRAPHIC_PORT)) == -1 ||
      (data->network->signal_fd = create_signal_fd()) == -1 ||
      (data->network->set = create_data_set(data->network)) == NULL)
    return (-1);
  data->network->graphic_fd = -1;
  return (0);
}

int	main_loop(t_data *data)
{
  if (init_network(data) == -1)
    return (84);
  while (1)
    {
      // Execution des actions des joueurs (boucle)
      if (check_sockets(data) == -1) // check connection graphique
	{
	  free_data(data);
	  return (84);
	}
      update_egg_status(data);
      usleep(100);
    }
  return (free_data(data));
}
