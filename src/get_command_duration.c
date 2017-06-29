/*
** get_command_duration.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Tue Jun 27 15:46:29 2017 Baptiste Veyssiere
** Last update Thu Jun 29 14:39:04 2017 Baptiste Veyssiere
*/

#include <string.h>
#include "server.h"
#include "action.h"

int		get_command_duration(char *command)
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
  return (duration);
}
