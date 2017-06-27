/*
** action.h for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Mon Jun 19 15:24:44 2017 Mathis Guilbon
** Last update Tue Jun 27 13:08:47 2017 Mathis Guilbon
*/

#ifndef PSU_2016_ZAPPY_ACTION_H
#  define PSU_2016_ZAPPY_ACTION_H

#  include "server.h"

typedef struct	s_act
{
  char 		*name;
  bool		(*func)(t_data *, t_player *, char *);
}		t_act;

static  t_act actions[] =
{
  {"Forward", action_forward},
  {"Right", action_right},
  {"Left", action_left},
  {"Look", action_look},
  {"Inventory", action_inventory},
  {"Broadcast", action_broadcast},
  {"Connect_nbr", action_connect_nbr},
  {"Fork", action_fork},
  {"Eject", action_eject},
  {"Take", action_take},
  {"Set", action_set},
  {"Incantation", action_incantation}
};

#endif /* !PSU_2016_ZAPPY_ACTION_H */
