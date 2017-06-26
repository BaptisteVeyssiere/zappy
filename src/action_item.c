

#include "action.h"

bool		action_take(t_data *data, t_player *player, char *prm)
{
  int		i;

  (void)data;
  i = -1;
  while (++i < ITEMNBR && strcmp(item[i], prm + 1) != 0);
  if (i < ITEMNBR)
    {
     player->inventory->item[i] += (i != FOOD) ? 1 : 126;
      if (data->map[player->pos->y][player->pos->x].item[i] > 0)
	--data->map[player->pos->y][player->pos->x].item[i];
      // ecrire ok
    }
  // ecrire ko
  return (true);
}

bool		action_set(t_data *data, t_player *player, char *prm)
{
  int		i;

  (void)data;
  i = -1;
  while (++i < ITEMNBR && strcmp(item[i], prm + 1) != 0);
  if (i < ITEMNBR && i != FOOD)
    {
      if (player->inventory->item[i] > 0)
	--player->inventory->item[i];
      ++data->map[player->pos->y][player->pos->x].item[i];
      // ecrire ok
    }
  // ecrire ko
  return (true);
}

bool		action_inventory(t_data *data, t_player *player, char *prm)
{
  char 		buff[MSG_LEN];

  (void)data;
  snprintf(buff, MSG_LEN, "[food %u, sibur %u, phiras %u, "
	   "linemate %u, mendiane %u, thystame %u, "
	   "deraumere %u]\n",
           player->inventory->item[FOOD],
	   player->inventory->item[SIBUR],
	   player->inventory->item[PHIRAS],
	   player->inventory->item[LINEMATE],
	   player->inventory->item[MENDIATE],
	   player->inventory->item[THYSTAME],
	   player->inventory->item[DERAUMERE]);
  // ecrire
  return (true);
}

bool		action_incantation(t_data *data, t_player *player, char *prm)
{
  if (!(incant[player->level - 1])(player->inventory))
    return (false);
  // ecrire ok
  return (true);
}

bool		action_look(t_data *data, t_player *player, char *prm)
{
  return (true);
}
