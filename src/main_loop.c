/*
** main_loop.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 21 15:33:39 2017 Baptiste Veyssiere
** Last update Wed Jun 28 15:36:25 2017 Mathis Guilbon
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
  data->network = NULL;
  if ((data->network = malloc(sizeof(t_network))) == NULL)
    return (write_error(__FILE__, __func__, __LINE__, -1));
  data->network->socket_fd[0] = -1;
  data->network->socket_fd[1] = -1;
  data->network->graphic_fd = -1;
  data->network->signal_fd = -1;
  data->network->set = NULL;
  data->network->graphic_buffer = NULL;
  if ((data->network->socket_fd[0] = bind_port(data->port)) == -1 ||
      (data->network->socket_fd[1] = bind_port(GRAPHIC_PORT)) == -1 ||
      (data->network->signal_fd = create_signal_fd()) == -1 ||
      (data->network->set = create_data_set(data->network)) == NULL)
    return (-1);
  data->network->graphic_fd = -1;
  data->network->graphic_ready = -1;
  data->network->graphic_buffer = NULL;
  return (0);
}

int	main_loop(t_data *data)
{
  if (init_network(data) == -1)
    {
      free_data(data);
      return (84);
    }
  while (1)
    {

      if (execute_actions(data) == -1 ||
	  update_player_status(data) == -1 ||
	  check_sockets(data) == -1)
	{
	  free_data(data);
	  return (84);
	}
      update_egg_status(data);
      update_action_status(data);
      usleep(100);
    }
  return (free_data(data));
}
