/*
** init_graphic.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_201
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Mon Jun 26 16:02:11 2017 Baptiste Veyssiere
** Last update Sat Jul  1 19:33:26 2017 Baptiste Veyssiere
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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
  if (data->freq > 200)
    {
      if (socket_write(data->network->graphic_fd,
		       "Frequence to high for graphic view\n") == -1 ||
	  close(data->network->graphic_fd) == -1)
	return (write_error(__FILE__, __func__, __LINE__, -1));
      data->network->graphic_fd = -1;
      return (0);
    }
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

int	init_graphic_fd(t_data *data)
{
  FD_CLR(data->network->graphic_fd, data->network->set);
  if (close(data->network->graphic_fd) == -1)
    return (write_error(__FILE__, __func__, __LINE__, -1));
  data->network->graphic_fd = -1;
  free(data->network->graphic_buffer);
  data->network->graphic_buffer = NULL;
  data->network->graphic_ready = -1;
  return (0);
}

int	get_graphic_info(t_data *data)
{
  int	ret;
  int	is_cmd;
  char	*command;

  if ((ret = read_socket(data->network->graphic_fd,
			 data->network->graphic_buffer)) == -1)
    return (init_graphic_fd(data));
  if (data->network->graphic_ready != 0)
    return (0);
  is_cmd = 0;
  while ((command = check_ring(data->network->graphic_buffer, 0, &is_cmd)))
    {
      if (strcmp(command, "GRAPHIC\0") == 0)
	{
	  printf("Le GUI est connecté\n");
	  data->network->graphic_ready = 1;
	  free(command);
	  return (send_graphic_info(data));
	}
      else if (socket_write(data->network->graphic_fd, "ko\n") == -1)
	return (0);
      free(command);
      is_cmd = 0;
    }
  return (is_cmd != 0 ? -1 : 0);
}
