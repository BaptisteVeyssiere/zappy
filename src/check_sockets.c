/*
** check_sockets.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Fri Jun 23 17:55:38 2017 Baptiste Veyssiere
** Last update Sun Jun 25 04:54:44 2017 Baptiste Veyssiere
*/

#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <strings.h>
#include "server.h"

static t_ringbuffer	*init_ringbuffer(void)
{
  t_ringbuffer		*elem;

  if (!(elem = malloc(sizeof(t_ringbuffer))))
    {
      write_error(__FILE__, __func__, __LINE__, 0);
      return (NULL);
    }
  bzero(elem->data, RINGLENGTH);
  elem->write_ptr = 0;
  elem->read_ptr = 0;
  return (elem);
}

static int		extend_queue(t_data *data)
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
  last->fd = fd;
  last->next = NULL;
  if (!(last->ringbuffer = init_ringbuffer()))
    return (-1);
  if (!(data->queue))
    data->queue = last;
  else
    {
      queue = data->queue;
      while (queue->next)
	queue = queue->next;
      queue->next = last;
    }
  FD_SET(fd, data->network->set);
  return (socket_write(fd, "WELCOME\n"));
}

static int	update_queue(t_data *data, fd_set *set)
{
  t_waiting_queue	*elem;
  t_waiting_queue	*tmp;
  t_waiting_queue	*prev;
  int			ret;

  elem = data->queue;
  prev = NULL;
  while (elem)
    {
      ret = 0;
      tmp = elem->next;
      if (FD_ISSET(elem->fd, set))
	{
	  if ((ret = check_team_wish(data, elem)) == -1)
	    return (-1);
	  if (ret == 1 && prev != NULL)
	    prev->next = tmp;
	  else if (ret == 1)
	    data->queue = tmp;
	}
      if (ret == 0)
	prev = elem;
      elem = tmp;
    }
  return (0);
}

static int	check_set(t_data *data, fd_set *set)
{
  if (FD_ISSET(data->network->signal_fd, set))
    return (check_signal(data->network->signal_fd));
  if (FD_ISSET(data->network->socket_fd[0], set) &&
      extend_queue(data) == -1)
    return (-1);
  if (update_queue(data, set) == -1)
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
