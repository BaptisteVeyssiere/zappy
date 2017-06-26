/*
** action.h for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Mon Jun 19 15:24:44 2017 Mathis Guilbon
** Last update Mon Jun 26 18:27:08 2017 Mathis Guilbon
*/

#ifndef PSU_2016_ZAPPY_ACTION_H
#  define PSU_2016_ZAPPY_ACTION_H

#  include "server.h"
#  include <string.h>

static	char *item_name[] =
{
  "food",
  "sibur",
  "phiras",
  "linemate",
  "mendiane",
  "thystame",
  "deraumere"
};

typedef struct	s_action
{
  char 		*name;
  bool		(*func)(t_data *, t_player *, char *);
}		t_action;

static  t_action[] =
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
  {"Death", action_dead},
  {"Take", action_take},
  {"Set", action_set},
  {"Incantation", action_incantation}
};

static		(*incant[7])(t_data *, t_player *, t_items *) =
{
  UpgradeToLvl2,
  UpgradeToLvl3,
  UpgradeToLvl4,
  UpgradeToLvl5,
  UpgradeToLvl6,
  UpgradeToLvl7,
  UpgradeToLvl8
};

/*
**	action_connect.c
*/

bool		eject(t_data *, t_player *, t_position *, char *);
bool		action_connect_nbr(t_data *, t_player *, char *);
bool		action_fork(t_data *, t_player *, char *);
bool		action_broadcast(t_data *, t_player *, char *);

/*
**	action_item.c
*/

bool		action_take(t_data *, t_player *, char *);
bool		action_set(t_data *, t_player *, char *);
bool		action_inventory(t_data *, t_player *, char *);
bool		action_incantation(t_data *, t_player *, char *);

/*
**	action_move.c
*/

void		getRealPosFrom(t_data *, t_pos *);
bool		action_forward(t_data *, t_player *, char *);
bool		action_right(t_data *, t_player *, char *);
bool		action_left(t_data *, t_player *, char *);
bool		action_eject(t_data *, t_player *, char *);

/*
**	incantation.c
*/

void		upgrade_player(t_data *, t_player *);
bool		enoughPeople(t_data *, t_player *, unsigned int);
bool		upgradeToLvl2(t_data *, t_player *, t_items *);
bool		upgradeToLvl3(t_data *, t_player *, t_items *);
bool		upgradeToLvl4(t_data *, t_player *, t_items *);

/*
**	incantation2.c
*/

bool		upgradeToLvl5(t_data *, t_player *, t_items *);
bool		upgradeToLvl6(t_data *, t_player *, t_items *);
bool		upgradeToLvl7(t_data *, t_player *, t_items *);
bool		upgradeToLvl8(t_data *, t_player *, t_items *);

/*
**	action_look.c
*/

bool		checkOverflow(int *, char *, int);
bool		lookOneCase(t_items *, int *, char *, int);
void		changeOffset(enum dir, t_position *, int *, int);
bool		action_look(t_data *, t_player *, char *);

#endif /* !PSU_2016_ZAPPY_ACTION_H */
