/*
** check_sockets.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Fri Jun 23 17:55:38 2017 Baptiste Veyssiere
** Last update Fri Jun 23 18:08:43 2017 Baptiste Veyssiere
*/

#include <unistd.h>
#include "server.h"

static int	check_set(t_data *data, fd_set *set)
{
  if (FD_ISSET(data->network->signal_fd, set))
    return (check_signal(data->network->signal_fd));
  return(0);
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
