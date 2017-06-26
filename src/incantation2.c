/*
** incantation2.c for zappy in /home/guilbom/rendu/PSU_2016_zappy
** 
** Made by guilbo_m
** Login   <mathis.guilbon@epitech.eu>
** 
** Started on  Mon Jun 26 12:01:39 2017 chalie_a
** Last update Mon Jun 26 12:01:57 2017 chalie_a
*/

#include "action.h"

bool		upgradeToLvl6(t_data *data, t_player *player, t_items *items)
{
  if (items->players > 0 && items->item[LINEMATE] > 0 &&
      items->item[DERAUMERE] > 1 && items->item[SIBUR] > 0 &&
      items->item[MENDIANE] > 2)
    {
      --items->item[LINEMATE];
      items->item[DERAUMERE] -= 2;
      --items->item[SIBUR];
      items->item[PHIRAS] -= 3;
      upgrade_player(data, player, 4);
    }
  return (true);
}

bool		upgradeToLvl7(t_data *data, t_player *player, t_items *items)
{
  if (items->players > 0 && items->item[LINEMATE] > 0 &&
      items->item[DERAUMERE] > 1 && items->item[SIBUR] > 2 &&
      items->item[PHIRAS] > 0)
    {
      --items->item[LINEMATE];
      items->item[DERAUMERE] -= 2;
      --items->item[SIBUR];
      items->item[PHIRAS] -= 3;
      upgrade_player(data, player, 6);
    }
  return (true);
}

bool		upgradeToLvl8(t_data *data, t_player *player, t_items *items)
{
  if (items->players > 0 && items->item[LINEMATE] > 1 &&
      items->item[DERAUMERE] > 1 && items->item[SIBUR] > 1 &&
      items->item[MENDIANE] > 1 && items->item[PHIRAS] > 1 &&
      items->item[THYSTAME] > 0)
    {
      items->item[LINEMATE] -= 2;
      items->item[DERAUMERE] -= 2;
      items->item[SIBUR] -= 2;
      items->item[MENDIANE] -= 2;
      items->item[PHIRAS] -= 2;
      --items->item[THYSTAME];
      upgrade_player(data, player, 6);
    }
  return (true);
}
