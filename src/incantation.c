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
  return (count >= needed);
}

bool		upgradeToLvl2(t_data *data, t_player *player, t_items *items)
{
  if (items->players > 0 && items->item[LINEMATE] > 0)
  {
    --items->item[LINEMATE];
    upgrade_player(data, player);
  }
  return (true);
}

bool		upgradeToLvl3(t_data *data, t_player *player, t_items *items)
{
  if (items->players > 1 && enoughPeople(data, player, 2) &&
      items->item[LINEMATE] > 0 && items->item[DERAUMERE] > 0 &&
      items->item[SIBUR] > 0)
    {
      --items->item[LINEMATE];
      --items->item[DERAUMERE];
      --items->item[SIBUR];
      upgrade_player(data, player);
    }
  return (true);
}

bool		upgradeToLvl4(t_data *data, t_player *player, t_items *items)
{
  if (items->players > 0 && enoughPeople(data, player, 2) &&
      items->item[LINEMATE] > 1 && items->item[SIBUR] > 0 &&
      items->item[PHIRAS] > 1)
    {
      items->item[LINEMATE] -= 2;
      --items->item[SIBUR];
      items->item[PHIRAS] -= 2;
      upgrade_player(data, player);
    }
  return (true);
}
