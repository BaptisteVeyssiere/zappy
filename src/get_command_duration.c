/*
** get_command_duration.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Tue Jun 27 15:46:29 2017 Baptiste Veyssiere
** Last update Sat Jul  1 01:24:45 2017 Baptiste Veyssiere
*/

#include <string.h>
#include "server.h"

int		get_command_duration(char *command)
{
  int		duration;
  int		i;
  static  t_act actions[] =
    {
      {"Forward", action_forward, 7},
      {"Right", action_right, 7},
      {"Left", action_left, 7},
      {"Look", action_look, 7},
      {"Inventory", action_inventory, 1},
      {"Broadcast ", action_broadcast, 7},
      {"Connect_nbr", action_connect_nbr, 0},
      {"Fork", action_fork, 42},
      {"Eject", action_eject, 7},
      {"Take ", action_take, 7},
      {"Set ", action_set, 7},
      {"Incantation", action_incantation, 300}
    };

  i = -1;
  duration = -2;
  while (++i < ACTION_NBR)
    if (strncmp(actions[i].name, command, strlen(actions[i].name)) == 0 &&
	(duration = actions[i].duration) == (int)actions[i].duration)
      i = ACTION_NBR;
  return (duration);
}
