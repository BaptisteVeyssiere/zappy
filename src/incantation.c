/*
** incantation.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Sun Jun 24 14:10:14 2017 Mathis Guilbon
** Last update Tue Jun 27 13:19:05 2017 Mathis Guilbon
*/

#include "action.h"

void		upgrade_player(t_data *data, t_player *player)
{
  t_player	*tmp;

  tmp = data->players_root;
  while (tmp != NULL)
    {
      if (tmp->pos->x == player->pos->x &&
	  tmp->pos->y = player->pos->y &&
	  tmp->level == player->level)
	++tmp->level;
      tmp = tmp->next;
    }
}

bool		enoughPeople(t_data *data, t_player *player, unsigned int needed)
{
  t_player	*tmp;
  int		count;

  tmp = data->players_root;
  count = 0;
  while (tmp != NULL)
  {
    if (tmp->pos->x == player->pos->x &&
        tmp->pos->y = player->pos->y &&
        tmp->level == player->level)
      ++count;
    tmp = tmp->next;
  }
  return (count == needed);
}

bool		upgradeToLvl2(t_data *data, t_player *player, t_items *items)
{
  if (items->players == 1 && items->item[LINEMATE] == 1 &&
      items->item[DERAUMERE] == 0 && items->item[SIBUR] == 0 &&
      items->item[MENDIANE] == 0 && items->item[PHIRAS] == 0 &&
      items->item[THYSTAME] == 0)
  {
    --items->item[LINEMATE];
    return (true);
  }
  return (false);
}

bool		upgradeToLvl3(t_data *data, t_player *player)
{
  t_items	*items;

  items = data->map[player->pos->y][player->pos->y];
  if (items->players == 2 && enoughPeople(data, player, 2) &&
      items->item[LINEMATE] == 1 && items->item[DERAUMERE] == 1 &&
      items->item[SIBUR] == 1 && items->item[MENDIANE] == 0 &&
      items->item[PHIRAS] == 0 && items->item[THYSTAME] == 0)
    {
      --items->item[LINEMATE];
      --items->item[DERAUMERE];
      --items->item[SIBUR];
      return (true);
    }
  return (false);
}

bool		upgradeToLvl4(t_data *data, t_player *player)
{
  t_items	*items;

  items = data->map[player->pos->y][player->pos->y];
  if (items->players == 2 && enoughPeople(data, player, 2) &&
      items->item[LINEMATE] == 2 && items->item[DERAUMERE] == 0 &&
      items->item[SIBUR] == 1 && items->item[MENDIANE] == 0 &&
      items->item[PHIRAS] == 2 && items->item[THYSTAME] == 0)
    {
      items->item[LINEMATE] -= 2;
      --items->item[SIBUR];
      items->item[PHIRAS] -= 2;
      return (true);
    }
  return (false);
}
