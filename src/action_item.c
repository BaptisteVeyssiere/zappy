/*
** action_item.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Mon Jun 19 15:37:31 2017 Mathis Guilbon
** Last update Tue Jun 27 13:18:04 2017 Mathis Guilbon
*/

#include "server.h"
#include "incantation.h"

bool		action_take(t_data *data, t_player *player, char *prm)
{
  int		i;

  (void)data;
  i = -1;
  while (++i < ITEMNBR && strcmp(item_name[i], prm + 1) != 0);
  if (i < ITEMNBR)
    {
      ++player->inventory->item[i];
      if (data->map[player->pos->y][player->pos->x].item[i] > 0)
	--data->map[player->pos->y][player->pos->x].item[i];
      return (socket_write(player->fd, "ok\n") != -1);
    }
  return (socket_write(player->fd, "ko\n") != -1);
}

bool		action_set(t_data *data, t_player *player, char *prm)
{
  int		i;

  (void)data;
  i = -1;
  while (++i < ITEMNBR && strcmp(item_name[i], prm + 1) != 0);
  if (i < ITEMNBR && i != FOOD)
    {
      if (player->inventory->item[i] > 0)
	--player->inventory->item[i];
      ++data->map[player->pos->y][player->pos->x].item[i];
      return (socket_write(player->fd, "ok\n") != -1);
    }
  return (socket_write(player->fd, "ko\n") != -1);
}

bool		action_inventory(t_data *data, t_player *player, char *prm)
{
  char 		buff[MSG_LEN];

  (void)data;
  (void)prm;
  snprintf(buff, MSG_LEN, "[food %u, sibur %u, phiras %u, "
	   "linemate %u, mendiane %u, thystame %u, "
	   "deraumere %u]\n",
           player->inventory->item[FOOD] * 126 + player->life,
	   player->inventory->item[SIBUR],
	   player->inventory->item[PHIRAS],
	   player->inventory->item[LINEMATE],
	   player->inventory->item[MENDIANE],
	   player->inventory->item[THYSTAME],
	   player->inventory->item[DERAUMERE]);
  return (socket_write(player->fd, buff) != -1);
}

bool		action_incantation(t_data *data, t_player *player, char *prm)
{
  char		buff[64];

  (void)prm;
  if (!(incant[player->level - 1])(data, player))
    return (socket_write(player->fd, "ko\n"));
  upgrade_player(data, player);
  snprintf(buff, 64, "Elevation underway\nCurrent level: %d\n", player->level);
  return (socket_write(player->fd, buff) != -1);
}
