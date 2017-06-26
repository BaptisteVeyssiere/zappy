/*
** send_basic_info.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Mon Jun 26 14:53:31 2017 Baptiste Veyssiere
** Last update Mon Jun 26 14:58:21 2017 Baptiste Veyssiere
*/

#include <strings.h>
#include <stdio.h>
#include "server.h"

int	send_basic_info(int fd, int free_slot, int width, int height)
{
  char	buff[20];

  bzero(buff, 20);
  if (sprintf(buff, "%d\n %d %d\n", free_slot, width, height) < 0 ||
      socket_write(fd, buff) == -1)
    return (-1);
  return (0);
}
