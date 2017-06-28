/*
** init_server.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 21 00:52:57 2017 Baptiste Veyssiere
** Last update Wed Jun 28 18:21:22 2017 Baptiste Veyssiere
*/

#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include "server.h"

int	bind_port(const int port)
{
  struct sockaddr_in	s_in;
  struct protoent	*pe;
  int			fd;
  int			yes;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  yes = 1;
  if (!(pe = getprotobyname("TCP")) ||
      (fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1 ||
      setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    return (write_error(__FILE__, __func__, __LINE__, -1));
  if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1 ||
      listen(fd, QUEUE_SIZE) == -1)
    {
      if (write_error(__FILE__, __func__, __LINE__, 0) == -1)
	return (-1);
      if (close(fd) == -1)
	return (write_error(__FILE__, __func__, __LINE__, -1));
      return (-1);
    }
  return (fd);
}
