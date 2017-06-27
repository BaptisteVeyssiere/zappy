/*
** get_command_duration.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Tue Jun 27 15:46:29 2017 Baptiste Veyssiere
** Last update Tue Jun 27 16:21:22 2017 Mathis Guilbon
*/

#include <string.h>
#include "server.h"
#include "action.h"

int		get_command_duration(char *command, int fd)
{
  int		duration;
  int		i;

  i = -1;
  duration = -2;
  while (++i < ACTION_NBR)
    if (strncmp(actions[i].name, command, strlen(actions[i].name)) == 0)
      {
        duration = actions[i].duration;
        i = ACTION_NBR;
      }
  if (duration == -2 && socket_write(fd, "ko\n") == -1)
    return (-1);
  return (duration);
}
