/*
** incantation2.c for zappy in /home/guilbom/rendu/PSU_2016_zappy
** 
** Made by guilbo_m
** Login   <mathis.guilbon@epitech.eu>
** 
** Started on  Mon Jun 26 12:01:39 2017 chalie_a
** Last update Tue Jun 27 15:36:03 2017 Mathis Guilbon
*/

#include "server.h"

bool		upgradeToLvl5(t_data *data, t_player *player, bool check)
{
  t_items	*items;

  items = &data->map[player->pos->y][player->pos->y];
  if (items->players > 0  && enoughPeople(data, player, 4) &&
      items->item[LINEMATE] == 1 && items->item[DERAUMERE] == 1 &&
      items->item[SIBUR] == 2 && items->item[MENDIANE] == 0 &&
      items->item[PHIRAS] == 1 && items->item[THYSTAME] == 0)
  {
    if (!check)
      {
	--items->item[LINEMATE];
	--items->item[DERAUMERE];
	items->item[SIBUR] -= 2;
	--items->item[PHIRAS];
      }
    return (true);
  }
  return (false);
}

bool		upgradeToLvl6(t_data *data, t_player *player, bool check)
{
  t_items	*items;

  items = &data->map[player->pos->y][player->pos->y];
  if (items->players > 0  && enoughPeople(data, player, 4) &&
      items->item[LINEMATE] == 1 && items->item[DERAUMERE] == 2 &&
      items->item[SIBUR] == 1 && items->item[MENDIANE] == 3 &&
      items->item[PHIRAS] == 0 && items->item[THYSTAME] == 0)
    {
      if (!check)
	{
	  --items->item[LINEMATE];
	  items->item[DERAUMERE] -= 2;
	  --items->item[SIBUR];
	  items->item[PHIRAS] -= 3;
	}
      return (true);
    }
  return (false);
}

bool		upgradeToLvl7(t_data *data, t_player *player, bool check)
{
  t_items	*items;

  items = &data->map[player->pos->y][player->pos->y];
  if (items->players > 0  && enoughPeople(data, player, 6) &&
      items->item[LINEMATE] == 1 && items->item[DERAUMERE] == 2 &&
      items->item[SIBUR] == 3 && items->item[MENDIANE] == 0 &&
      items->item[PHIRAS] == 1 && items->item[THYSTAME] == 0)
    {
      if (!check)
	{
	  --items->item[LINEMATE];
	  items->item[DERAUMERE] -= 2;
	  --items->item[SIBUR];
	  items->item[PHIRAS] -= 3;
	}
      return (true);
    }
  return (false);
}

bool		upgradeToLvl8(t_data *data, t_player *player, bool check)
{
  t_items	*items;

  items = &data->map[player->pos->y][player->pos->y];
  if (items->players > 0  && enoughPeople(data, player, 6) &&
      items->item[LINEMATE] == 2 && items->item[DERAUMERE] == 2 &&
      items->item[SIBUR] == 2 && items->item[MENDIANE] == 2 &&
      items->item[PHIRAS] == 2 && items->item[THYSTAME] == 1)
    {
      if (!check)
	{
	  items->item[LINEMATE] -= 2;
	  items->item[DERAUMERE] -= 2;
	  items->item[SIBUR] -= 2;
	  items->item[MENDIANE] -= 2;
	  items->item[PHIRAS] -= 2;
	  --items->item[THYSTAME];
	}
      return (true);
    }
  return (false);
}
