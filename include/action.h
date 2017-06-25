//
// Created by root on 21/06/17.
//

#ifndef PSU_2016_ZAPPY_ACTION_H
#  define PSU_2016_ZAPPY_ACTION_H

#  include "server.h"
#  include <string.h>

enum {
  FOOD,
  SIBUR,
  PHIRAS,
  LINEMATE,
  MENDIANE,
  THYSTAME,
  DERAUMERE,
  ITEMNBR
};

static	*char[] =
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
  {"Forward", action_forward},//
  {"Right", action_right},//
  {"Left", action_left},//
  {"Look", action_look},
  {"Inventory", action_inventory},//
  {"Broadcast", action_broadcast},
  {"Connect_nbr", action_connect_nbr},
  {"Fork", action_fork},
  {"Eject", action_eject},//
  {"Death", action_dead}, // free player et envoie reponse "dead"
  {"Take", action_take},//
  {"Set", action_set},//
  {"Incantation", action_incantation}//
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

#endif //PSU_2016_ZAPPY_ACTION_H
