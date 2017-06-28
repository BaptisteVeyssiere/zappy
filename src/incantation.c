/*
** incantation.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Sun Jun 24 14:10:14 2017 Mathis Guilbon
** Last update Wed Jun 28 15:53:08 2017 Mathis Guilbon
*/

#include "server.h"

void		upgrade_player(t_data *data, t_player *player)
{
  t_player	*tmp;

  tmp = data->players_root;
  while (tmp != NULL)
    {
      if (tmp->pos->x == player->pos->x &&
	  tmp->pos->y == player->pos->y &&
	  tmp->level == player->level)
	++tmp->level;
      tmp = tmp->next;
    }
}

bool		enough_people(t_data *data, t_player *player, unsigned int needed)
{
  t_player	*tmp;
  unsigned int	count;

  tmp = data->players_root;
  count = 0;
  while (tmp != NULL)
  {
    if (tmp->pos->x == player->pos->x &&
        tmp->pos->y == player->pos->y &&
        tmp->level == player->level)
      ++count;
    tmp = tmp->next;
  }
  return (count == needed);
}

bool		upgrade_to_lvl2(t_data *data, t_player *player)
{
  t_items	*items;

  items = &data->map[player->pos->y][player->pos->x];
  return (items->players == 1 && items->item[LINEMATE] == 1 &&
	  items->item[DERAUMERE] == 0 && items->item[SIBUR] == 0 &&
	  items->item[MENDIANE] == 0 && items->item[PHIRAS] == 0 &&
	  items->item[THYSTAME] == 0);
}

bool		upgrade_to_lvl3(t_data *data, t_player *player)
{
  t_items	*items;

  items = &data->map[player->pos->y][player->pos->x];
  return (items->players == 2 && enough_people(data, player, 2) &&
	  items->item[LINEMATE] == 1 && items->item[DERAUMERE] == 1 &&
	  items->item[SIBUR] == 1 && items->item[MENDIANE] == 0 &&
	  items->item[PHIRAS] == 0 && items->item[THYSTAME] == 0);
}

bool		upgrade_to_lvl4(t_data *data, t_player *player)
{
  t_items	*items;

  items = &data->map[player->pos->y][player->pos->x];
  return (items->players == 2 && enough_people(data, player, 2) &&
	  items->item[LINEMATE] == 2 && items->item[DERAUMERE] == 0 &&
	  items->item[SIBUR] == 1 && items->item[MENDIANE] == 0 &&
	  items->item[PHIRAS] == 2 && items->item[THYSTAME] == 0);
}
