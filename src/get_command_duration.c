/*
** get_command_duration.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Tue Jun 27 15:46:29 2017 Baptiste Veyssiere
** Last update Tue Jun 27 16:06:18 2017 Baptiste Veyssiere
*/

#include <string.h>
#include "server.h"

int		get_command_duration(char *command, int fd)
{
  int		duration;
  static char	*command_list[12] =
    {
      "Forward\0", "Right\0", "Left\0", "Look\0", "Inventory\0", "Broadcast ",
      "Connect_nbr\0", "Fork\0", "Eject\0", "Take ", "Set ", "Incantation\0"
    };
  static int	command_duration[12] =
    {
      7, 7, 7, 7, 1, 7, 0, 42, 7, 7, 7, 300
    };
  int		i;

  i = -1;
  duration = -2;
  while (++i < 12)
    if (strncmp(command_list[i], command, strlen(command_list[i])) == 0)
      {
        duration = command_duration[i];
        i = 12;
      }
  if (duration == -2 && socket_write(fd, "ko\n") == -1)
    return (-1);
  return (duration);
}
