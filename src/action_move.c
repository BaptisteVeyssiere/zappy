//
// Created by guilbo_m on 21/06/17.
//

#include "action.h"

void		getRealPosFrom(t_data *data, t_pos *pos)
{
  if (pos->y >= data->height - 1)
    pos->y -= data->height - 1;
  else if (pos->y < 0)
    pos->y += data->height - 1;
  if (pos->x >= data->width - 1)
    pos->x -= data->width - 1;
  else if (x < 0)
    pos->x += data->width - 1;  
}

bool		action_forward(t_data *data, t_player *player, char *prm)
{
  enum dir	dir;

  (void)prm;
  --data->map[player->pos->y][player->pos->x].players;
  dir = player->direction;
  player->pos->x += (dir == RIGHT) ? 1 : (dir == LEFT) ? -1 : 0;
  player->pos->y += (dir == DOWN) ? 1 : (dir == UP) ? -1 : 0;
  getRealPosFrom(data, player->pos);
  ++data->map[player->pos->y][player->pos->x].players;
  // ecrire ok
  return (true);
}

bool		action_right(t_data *data, t_player *player, char *prm)
{
  (void)data;
  (void)prm;
  if ((++player->direction) == UNKNOWN)
    player->direction = 0;
  // ecrire ok
  return (true);
}

bool		action_left(t_data *data, t_player *player, char *prm)
{
  (void)data;
  (void)prm;
  if ((--player->direction) < 0)
    player->direction = LEFT;
  // ecrire ok
  return (true);
}

bool		action_eject(t_data *data, t_player *player, char *prm)
{
  enum dir	dir;
  t_pos		off;
  t_player	*tmp;

  (void)prm;
  dir = player->direction;
  off.x = player->pos->x + ((dir == RIGHT) ? 1 : (dir == LEFT) ? -1 : 0);
  off.y = player->pos->y + ((dir == DOWN) ? 1 : (dir == UP) ? -1 : 0);
  getRealPosFrom(data, &off);
  tmp = data->players_root;
  while (tmp != NULL)
    {
      if (tmp->pos->x == player->pos->x &&
	  tmp->pos->y == player->pos->y &&
	  tmp != player)
	{
	  // send "eject: dir\n"
	  --data->map[player->pos->y][player->pos->x].players;
	  ++data->map[off.y][off.x].players;
	  tmp.x = off.x;
	  tmp.y = off.y;
	}
      tmp = tmp->next;
    }
  return (true);
}
