/*
** incantation2.c for zappy in /home/guilbom/rendu/PSU_2016_zappy
** 
** Made by guilbo_m
** Login   <mathis.guilbon@epitech.eu>
** 
** Started on  Mon Jun 26 12:01:39 2017 chalie_a
** Last update Wed Jun 28 13:51:20 2017 Mathis Guilbon
*/

#include "server.h"

bool		upgrade_to_lvl5(t_data *data, t_player *player)
{
  t_items	*items;

  items = &data->map[player->pos->y][player->pos->y];
  return (items->players > 0  && enough_people(data, player, 4) &&
	  items->item[LINEMATE] == 1 && items->item[DERAUMERE] == 1 &&
	  items->item[SIBUR] == 2 && items->item[MENDIANE] == 0 &&
	  items->item[PHIRAS] == 1 && items->item[THYSTAME] == 0);
}

bool		upgrade_to_lvl6(t_data *data, t_player *player)
{
  t_items	*items;

  items = &data->map[player->pos->y][player->pos->y];
  return (items->players > 0  && enough_people(data, player, 4) &&
	  items->item[LINEMATE] == 1 && items->item[DERAUMERE] == 2 &&
	  items->item[SIBUR] == 1 && items->item[MENDIANE] == 3 &&
	  items->item[PHIRAS] == 0 && items->item[THYSTAME] == 0);
}

bool		upgrade_to_lvl7(t_data *data, t_player *player)
{
  t_items	*items;

  items = &data->map[player->pos->y][player->pos->y];
  return (items->players > 0  && enough_people(data, player, 6) &&
	  items->item[LINEMATE] == 1 && items->item[DERAUMERE] == 2 &&
	  items->item[SIBUR] == 3 && items->item[MENDIANE] == 0 &&
	  items->item[PHIRAS] == 1 && items->item[THYSTAME] == 0);
}

bool		upgrade_to_lvl8(t_data *data, t_player *player)
{
  t_items	*items;

  items = &data->map[player->pos->y][player->pos->y];
  return (items->players > 0  && enough_people(data, player, 6) &&
	  items->item[LINEMATE] == 2 && items->item[DERAUMERE] == 2 &&
	  items->item[SIBUR] == 2 && items->item[MENDIANE] == 2 &&
	  items->item[PHIRAS] == 2 && items->item[THYSTAME] == 1);
}
