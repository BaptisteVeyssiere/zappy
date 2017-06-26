/*
** incantation.c for zappy in /home/guilbom/rendu/PSU_2016_zappy
** 
** Made by guilbo_m
** Login   <mathis.guilbon@epitech.eu>
** 
** Started on  Mon Jun 26 12:00:51 2017 chalie_a
** Last update Mon Jun 26 12:01:24 2017 chalie_a
*/

#include "action.h"

void		upgrade_player(t_data *data, t_player *player, unsigned int toUp)
{
  t_player	*tmp;

  --toUp;
  ++player->level;
  tmp = data->players_root;
  while (toUp > 0 && tmp != NULL)
    {
      if (tmp != player)
	++tmp->level;
      tmp = tmp->next;
    }
}

bool		upgradeToLvl2(t_data *data, t_player *player, t_items *items)
{
  if (items->players > 0 && items->item[LINEMATE] > 0)
    {
      --items->item[LINEMATE];
      upgrade_player(data, player, 1);
    }
  return (true);
}

bool		upgradeToLvl3(t_data *data, t_player *player, t_items *items)
{
  if (items->players > 0 && items->item[LINEMATE] > 0 &&
      items->item[DERAUMERE] > 0 && items->item[SIBUR] > 0)
    {
      --items->item[LINEMATE];
      --items->item[DERAUMERE];
      --items->item[SIBUR];
      upgrade_player(data, player, 2);
    }
  return (true);
}

bool		upgradeToLvl4(t_data *data, t_player *player, t_items *items)
{
  if (items->players > 0 && items->item[LINEMATE] > 1 &&
      items->item[SIBUR] > 0 && items->item[PHIRAS] > 1)
    {
      items->item[LINEMATE] -= 2;
      --items->item[SIBUR];
      items->item[PHIRAS] -= 2;
      upgrade_player(data, player, 2);
    }
  return (true);
}

bool		upgradeToLvl5(t_data *data, t_player *player, t_items *items)
{
  if (items->players > 0 && items->item[LINEMATE] > 0 &&
      items->item[DERAUMERE] > 0 && items->item[SIBUR] > 1 &&
      items->item[PHIRAS] > 1)
    {
      --items->item[LINEMATE];
      --items->item[DERAUMERE];
      items->item[SIBUR] -= 2;
      --items->item[PHIRAS];
      upgrade_player(data, player, 4);
    }
  return (true);
}
