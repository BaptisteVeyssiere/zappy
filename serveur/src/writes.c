/*
** writes.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zapp
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sat Jun 24 16:22:07 2017 Baptiste Veyssiere
** Last update Sat Jul  1 19:59:06 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

int	write_error(const char *file, const char *func,
		    const int line, const int ret)
{
  char	msg[MSG_LEN];

  if (snprintf(msg, MSG_LEN,
	       "In file %s, function %s, line %d", file, func, line) < 0)
    return (-1);
  perror(msg);
  return (ret);
}

int	socket_write(int fd, char *str)
{
  int	size;
  int	ret;
  int	ret2;

  printf("<%s>\n", str);
  size = strlen(str);
  ret2 = 1;
  while (size > 0)
    {

      if ((ret = write(fd, str, strlen(str))) == 0 && ret2 == 0)
	return (-2);
      if (ret == -1)
	return (write_error(__FILE__, __func__, __LINE__, -1));
      size -= ret;
      str += ret;
      printf("ret = %d\n", ret);
      ret2 = ret;
    }
  return (0);
}
