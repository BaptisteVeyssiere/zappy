/*
** action.h for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Mon Jun 19 15:24:44 2017 Mathis Guilbon
** Last update Tue Jun 27 15:42:47 2017 Mathis Guilbon
*/

#ifndef PSU_2016_ZAPPY_ACTION_H
#  define PSU_2016_ZAPPY_ACTION_H

#  include "server.h"

#  define ACTION_NBR 12

typedef struct	s_act
{
  char 		*name;
  bool		(*func)(t_data *, t_player *, char *);
  unsigned int	duration;
}		t_act;

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

#endif /* !PSU_2016_ZAPPY_ACTION_H */
