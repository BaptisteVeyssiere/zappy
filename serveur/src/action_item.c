/*
** action_item.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
**
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
**
** Started on  Mon Jun 19 15:37:31 2017 Mathis Guilbon
** Last update Sun Jul  2 22:10:47 2017 Baptiste Veyssiere
*/

#include <string.h>
#include <stdio.h>
#include "server.h"

bool			action_take(t_data *data, t_player *player, char *prm)
{
  int			i;
  static const char	*item_name[7] =
    {
      "food", "linemate", "deraumere", "sibur",
      "mendiane", "phiras", "thystame"
    };

  i = -1;
  while (++i < ITEMNBR && strcmp(item_name[i], prm) != 0);
  if (i < ITEMNBR && data->map[player->pos->y][player->pos->x].item[i] > 0)
    {
      ++player->inventory->item[i];
      if (data->map[player->pos->y][player->pos->x].item[i] > 0)
	{
	  --data->map[player->pos->y][player->pos->x].item[i];
	  if (respawn(data, i) == -1)
	    return (-1);
	}
      if (graphic_take(data, player, i) == -1)
	return (false);
      return (socket_write(player->fd, "ok\n") != -1);
    }
  return (socket_write(player->fd, "ko\n") != -1);
}

bool			action_set(t_data *data, t_player *player, char *prm)
{
  int			i;
  static const char	*item_name[] =
    {
      "food",
      "linemate",
      "deraumere",
      "sibur",
      "mendiane",
      "phiras",
      "thystame"
    };

  i = -1;
  while (++i < ITEMNBR && strcmp(item_name[i], prm) != 0);
  if (i < ITEMNBR && player->inventory->item[i] > 0)
    {
      --player->inventory->item[i];
      ++data->map[player->pos->y][player->pos->x].item[i];
      if (graphic_put(data, player, i) == -1)
	return (false);
      return (socket_write(player->fd, "ok\n") != -1);
    }
  return (socket_write(player->fd, "ko\n") != -1);
}

bool		action_inventory(UNUSED t_data *data, t_player *player,
				 UNUSED char *prm)
{
  char 		buff[MSG_LEN];

  snprintf(buff, MSG_LEN, "[ food %u, sibur %u, phiras %u, "
	   "linemate %u, mendiane %u, thystame %u, "
	   "deraumere %u ]\n",
           player->inventory->item[FOOD],
	   player->inventory->item[SIBUR],
	   player->inventory->item[PHIRAS],
	   player->inventory->item[LINEMATE],
	   player->inventory->item[MENDIANE],
	   player->inventory->item[THYSTAME],
	   player->inventory->item[DERAUMERE]);
  return (socket_write(player->fd, buff) != -1);
}

static bool	upgrade_player(t_data *data, t_player *player,
			       bool s, unsigned int level)
{
  t_player	*tmp;
  t_incantation	*_tmp;
  char		buff[32];

  _tmp = player->action->list;
  if (snprintf(buff, 32, "ko\n") < 0 ||
      pie(data, player->pos->x, player->pos->y, s == false ? 0 : 1) == -1 ||
      (s && snprintf(buff, 32, "Current level: %d\n", player->level + 1) < 0))
      return (false);
  while (_tmp != NULL)
    if (_tmp->player != NULL)
      {
	tmp = _tmp->player;
	if (tmp->pos->x == player->pos->x && tmp->pos->y == player->pos->y &&
	    tmp->level == level)
	  {
	    tmp->level = s == true ? (tmp->level + 1) : tmp->level;
	    if (socket_write(tmp->fd, buff) == -1 || plv(data, tmp) == -1)
	      return (false);
	  }
	else if (plv(data, tmp) == -1 || socket_write(tmp->fd, "ko\n") == -1)
	  return (false);
	_tmp = _tmp->next;
      }
  return (bct(data) == -1 ? false : true);
}

bool		action_incantation(t_data *data,
				   t_player *player, UNUSED char *prm)
{
  bool		ret;
  static bool	(*incant[7])(t_data *, t_player *) =
    {
      upgrade_to_lvl2,
      upgrade_to_lvl3,
      upgrade_to_lvl4,
      upgrade_to_lvl5,
      upgrade_to_lvl6,
      upgrade_to_lvl7,
      upgrade_to_lvl8
    };

  ret = (incant[player->level - 1])(data, player);
  return (upgrade_player(data, player, ret, player->level));
}
