/*
** action_look.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Mon Jun 26 17:31:29 2017 Mathis Guilbon
** Last update Mon Jun 26 18:20:58 2017 Mathis Guilbon
*/

#include "action.h"

bool		checkOverflow(int *written, char *buff, int fd)
{
  if (*written >= 490)
    {
      *written = 0;
      if (socket_write(fd, buff) == -1)
	return (false);
    }
  return (true);
}

bool		lookOneCase(t_items *item, int *written, char *buff, int fd)
{
  int		i;
  int		j;

  i = -1;
  while (++i < item->players)
    {
      *written += snprintf(buff + *written, 512 - *written, " player");
      if (!checkOverflow(written, buff, fd))
	return (false);
    }
  j = -1;
  while (++j < ITEMNBR)
    {
      i = -1;
      while (++i < item->item[j])
	{
	  *written += snprintf(buff + *written, 512 - *written, " %s", item_name[j]);
	  if (!checkOverflow(written, buff, fd))
	    return (false);
	}
    }
  return (true);
}

void		changeOffset(enum dir dir, t_position *off, int *turn, int saw)
{
  if (saw + 1 == *turn)
    {
      if (dir == UP || dir == DOWN)
	{
	  off->x += (dir == UP) ? -*turn : *turn;
	  off->y += (dir == UP) ? -1 : 1;
	}
      else if (dir == RIGHT || dir == LEFT)
	{
	  off->x += (dir == RIGHT) ? 1 : -1;
	  off->y += (dir == RIGHT) ? -*turn : *turn;
	}
      *turn += *turn + 2;
    }
  off->x += (dir == UP) ? 1 : (dir == DOWN) ? -1 : 0;
  off->y += (dir == RIGHT) ? 1 : (dir == LEFT) ? -1 : 0;
}

bool		action_look(t_data *data, t_player *player, char *prm)
{
  char		buff[512];
  int		toSee;
  int	      	saw;
  t_pos		off;
  int		written;
  int		turn;
  
  turn = 1;
  saw = -1;
  written = 1;
  buff[0] = '[';
  toSee = pow(2, player->level + 1);
  off.x = player->pos->x;
  off.y = player->pos->y;
  while (++saw < toSee)
    {
      getRealPosFrom(data, &off);
      if (!lookOneCase(data, &off, &written, buff))
	return (false);
      written += snprintf(buff + written, 512 - written, (saw + 1 == toSee) ? " ]" : ",");
      changeOffset(player->dir, &off, &turn, saw);
    }
  return (socket_write(player->fd, buff) != -1);
}
