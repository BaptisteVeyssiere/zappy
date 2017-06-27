/*
** init_graphic.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Mon Jun 26 16:02:11 2017 Baptiste Veyssiere
** Last update Tue Jun 27 15:29:09 2017 Baptiste Veyssiere
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

int	init_graphic(t_data *data)
{
  struct sockaddr_in	s_in;
  socklen_t		s_in_size;

  s_in_size = sizeof(s_in);
  if (data->network->graphic_ready >= 0)
    return (0);
  if ((data->network->graphic_fd =
       accept(data->network->socket_fd[1],
	      (struct sockaddr *)&s_in, &s_in_size)) == -1)
    return (write_error(__FILE__, __func__, __LINE__, -1));
  if (!(data->network->graphic_buffer = init_ringbuffer()) ||
      socket_write(data->network->graphic_fd, "BIENVENUE\n") == -1)
    return (-1);
  FD_SET(data->network->graphic_fd, data->network->set);
  data->network->graphic_ready = 0;
  return (0);
}

static int	send_graphic_info(t_data *data)
{
  if (msz(data) == -1 || sgt(data) == -1 || bct(data) == -1 ||
      tna(data) == -1 || init_pnw(data) == -1 || init_enw(data) == -1)
    return (-1);
  return (0);
}

int	get_graphic_info(t_data *data)
{
  int	ret;
  int	is_cmd;
  char	*command;

  if (data->network->graphic_ready != 0)
    return (0);
  if ((ret = read_socket(data->network->graphic_fd,
			 data->network->graphic_buffer)) == -1)
    {
      FD_CLR(data->network->graphic_fd, data->network->set);
      return (0);
    }
  is_cmd = 0;
  while ((command = check_ring(data->network->graphic_buffer, 0, &is_cmd)))
    {
      if (strcmp(command, "GRAPHIC\0") == 0)
	{
	  data->network->graphic_ready = 1;
	  free(command);
	  return (send_graphic_info(data));
	}
      free(command);
      is_cmd = 0;
    }
  return (is_cmd != 0 ? -1 : 0);
}
