/*
** action_look.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Mon Jun 26 17:05:23 2017 Mathis Guilbon
** Last update Tue Jun 27 16:25:34 2017 Mathis Guilbon
*/

#include "server.h"
#include "item_name.h"

static int	power(int nb, int p)
{
  int		i;
  int		mul;

  if (p == 0)
    return (1);
  i = 0;
  mul = nb;
  while (++i < p)
    nb *= mul;
  return (nb);
}

static bool	checkOverflow(int *written, char *buff, int fd)
{
  if (*written >= MSG_LEN - 32)
    {
      *written = 0;
      if (socket_write(fd, buff) == -1)
	return (false);
    }
  return (true);
}

static bool	lookOneCase(t_items *item, int *written, char *buff, int fd)
{
  int		i;
  int		j;

  i = -1;
  while (++i < (int)item->players)
    {
      *written += snprintf(buff + *written, MSG_LEN - *written, " player");
      if (!checkOverflow(written, buff, fd))
	return (false);
    }
  j = -1;
  while (++j < ITEMNBR)
    {
      i = -1;
      while (++i < (int)item->item[j])
	{
	  *written += snprintf(buff + *written, MSG_LEN - *written,
			       " %s", item_name[j]);
	  if (!checkOverflow(written, buff, fd))
	    return (false);
	}
    }
  return (true);
}

static void	changeOffset(enum dir dir, t_position *off, int *line, int saw)
{
  if (saw + 1 == *line)
    {
      if (dir == UP || dir == DOWN)
	{
	  off->x += (dir == UP) ? -*line : *line;
	  off->y += (dir == UP) ? -1 : 1;
	}
      else if (dir == RIGHT || dir == LEFT)
	{
	  off->x += (dir == RIGHT) ? 1 : -1;
	  off->y += (dir == RIGHT) ? -*line : *line;
	}
      *line += *line + 2;
    }
  else
    {
      off->x += (dir == UP) ? 1 : (dir == DOWN) ? -1 : 0;
      off->y += (dir == RIGHT) ? 1 : (dir == LEFT) ? -1 : 0;
    }
}

bool		action_look(t_data *data, t_player *player, char *prm)
{
  char		buff[MSG_LEN];
  int		toSee;
  int	      	saw;
  t_position	off;
  int		written;
  int		line;

  (void)prm;
  line = 1;
  saw = -1;
  written = 1;
  buff[0] = '[';
  toSee = power(2, player->level + 1);
  off.x = player->pos->x;
  off.y = player->pos->y;
  while (++saw < toSee)
    {
      getRealPosFrom(data, &off);
      if (!lookOneCase(&data->map[off.y][off.x], &written, buff, player->fd))
	return (false);
      written += snprintf(buff + written, MSG_LEN - written,
			  (saw + 1 == toSee) ? " ]" : ",");
      changeOffset(player->direction, &off, &line, saw);
    }
  return (socket_write(player->fd, buff) != -1);
}
