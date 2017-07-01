/*
** incantation.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
**
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
**
** Started on  Sun Jun 24 14:10:14 2017 Mathis Guilbon
** Last update Sat Jul  1 15:10:52 2017 Baptiste Veyssiere
*/

#include <unistd.h>
#include "server.h"

bool		incant_underway(t_data *data, t_player *player)
{
  t_player	*tmp;

  tmp = data->players_root;
  if (pic_init(data, player) == -1)
    return (false);
  while (tmp != NULL)
    {
      if (tmp->pos->x == player->pos->x &&
	  tmp->pos->y == player->pos->y &&
	  tmp->level == player->level &&
	  (socket_write(tmp->fd, "Elevation underway\n") == -1 ||
	   (tmp != player && pic(data, tmp) == -1)))
	return (false);
      tmp = tmp->next;
    }
  if (pic_end(data) == -1)
    return (false);
  return (true);
}

bool		enough_people(t_data *data, t_player *player,
			      unsigned int needed)
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
  if (items->players == 1 && items->item[LINEMATE] == 1 &&
      items->item[DERAUMERE] == 0 && items->item[SIBUR] == 0 &&
      items->item[MENDIANE] == 0 && items->item[PHIRAS] == 0 &&
      items->item[THYSTAME] == 0)
    return (true);
  return (false);
}

bool		upgrade_to_lvl3(t_data *data, t_player *player)
{
  t_items	*items;

  items = &data->map[player->pos->y][player->pos->x];
  if (items->players == 2 && enough_people(data, player, 2) &&
      items->item[LINEMATE] == 1 && items->item[DERAUMERE] == 1 &&
      items->item[SIBUR] == 1 && items->item[MENDIANE] == 0 &&
      items->item[PHIRAS] == 0 && items->item[THYSTAME] == 0)
    return (true);
  return (false);
}

bool		upgrade_to_lvl4(t_data *data, t_player *player)
{
  t_items	*items;

  items = &data->map[player->pos->y][player->pos->x];
  if (items->players == 2 && enough_people(data, player, 2) &&
      items->item[LINEMATE] == 2 && items->item[DERAUMERE] == 0 &&
      items->item[SIBUR] == 1 && items->item[MENDIANE] == 0 &&
      items->item[PHIRAS] == 2 && items->item[THYSTAME] == 0)
    return (true);
  return (false);
}
