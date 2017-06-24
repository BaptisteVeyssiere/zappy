/*
** check_sockets.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Fri Jun 23 17:55:38 2017 Baptiste Veyssiere
** Last update Sat Jun 24 15:57:12 2017 Baptiste Veyssiere
*/

#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <stdio.h>
#include "server.h"

static int		update_queue(t_data *data)
{
  struct sockaddr_in	s_in;
  socklen_t		s_in_size;
  t_waiting_queue	*last;
  t_waiting_queue	*queue;
  int			fd;

  s_in_size = sizeof(s_in);
  if ((fd = accept(data->network->socket_fd[0],
		   (struct sockaddr *)&s_in, &s_in_size)) == -1 ||
      (last = malloc(sizeof(t_waiting_queue))) == NULL)
    return (write_error(__FILE__, __func__, __LINE__, -1));
  last->team = NULL;
  last->fd = fd;
  last->next = NULL;
  if (!(data->queue))
    data->queue = last;
  else
    {
      queue = data->queue;
      while (queue->next)
	queue = queue->next;
      queue->next = last;
    }
  printf("Connexion of client fd = %d\n", last->fd);
  return (0);
}

static int	check_set(t_data *data, fd_set *set)
{
  if (FD_ISSET(data->network->signal_fd, set))
    return (check_signal(data->network->signal_fd));
  else if (FD_ISSET(data->network->socket_fd[0], set) &&
	   update_queue(data) == -1)
    return (-1);
  return (0);
}

int			check_sockets(t_data *data)
{
  struct timeval	timerange;
  int			ret;
  fd_set		copy;

  timerange.tv_sec = 0;
  timerange.tv_usec = 0;
  copy = *(data->network->set);
  if ((ret = select(FD_SETSIZE, &copy, NULL, NULL, &timerange)) == -1)
    return (write_error(__FILE__, __func__, __LINE__, -1));
  if (ret > 0 && (ret = check_set(data, &copy)))
    return (ret);
  return (0);
}
