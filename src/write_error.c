/*
** write_error.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 21 00:43:44 2017 Baptiste Veyssiere
** Last update Sat Jun 24 16:12:06 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <errno.h>
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
