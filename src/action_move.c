/*
** action_move.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Mon Jun 19 16:38:50 2017 Mathis Guilbon
** Last update Tue Jun 27 16:28:30 2017 Mathis Guilbon
*/

#include "server.h"

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
  return (socket_write(player->fd, "ok\n") != -1);
}

bool		action_right(t_data *data, t_player *player, char *prm)
{
  (void)data;
  (void)prm;
  if ((++player->direction) == UNKNOWN)
    player->direction = 0;
  return (socket_write(player->fd, "ok\n") != -1);
}

bool		action_left(t_data *data, t_player *player, char *prm)
{
  (void)data;
  (void)prm;
  if ((--player->direction) <= 0)
    player->direction = LEFT;
  return (socket_write(player->fd, "ok\n") != -1);
}

static bool	eject(t_data *data, t_player *player, t_position *off, char *buff)
{
  t_player	*tmp;

  tmp = data->players_root;
  while (tmp != NULL)
    {
      if (tmp->pos->x == player->pos->x &&
	  tmp->pos->y == player->pos->y &&
	  tmp != player)
	{
	  if (socket_write(tmp->fd, buff) == -1)
	    return (false);
	  --data->map[player->pos->y][player->pos->x].players;
	  ++data->map[off->y][off->x].players;
	  tmp->pos->x = off->x;
	  tmp->pos->y = off->y;
	}
      tmp = tmp->next;
    }
  return (true);
}

bool		action_eject(t_data *data, t_player *player, char *prm)
{
  enum dir	dir;
  char		buff[32];
  t_position	off;

  (void)prm;
  if (data->map[player->pos->y][player->pos->x].players < 2)
    return (socket_write(player->fd, "ko\n"));
  dir = player->direction;
  snprintf(buff, 32, "eject: %d\n", dir);
  off.x = player->pos->x + ((dir == RIGHT) ? 1 : (dir == LEFT) ? -1 : 0);
  off.y = player->pos->y + ((dir == DOWN) ? 1 : (dir == UP) ? -1 : 0);
  getRealPosFrom(data, &off);
  return (eject(data, player, &off, buff));
}
