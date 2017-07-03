/*
** action_look.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
**
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
**
** Started on  Mon Jun 26 17:05:23 2017 Mathis Guilbon
** Last update Sun Jul  2 15:45:49 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "server.h"

static bool	check_overflow(int *written, char *buff, int fd)
{
  if (*written >= MSG_LEN - 32)
    {
      *written = 0;
      bzero(buff, MSG_LEN);
      if (socket_write(fd, buff) == -1)
	return (false);
    }
  return (true);
}

static bool		look_one_case(t_items *item, int *written,
				      char *buff, int fd)
{
  int			i;
  int			j;
  static const char	*item_name[7] =
    {
      "food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"
    };

  i = -1;
  while (++i < (int)item->players)
    {
      *written += snprintf(buff + *written, MSG_LEN - *written, " player");
      if (!check_overflow(written, buff, fd))
	return (false);
    }
  j = -1;
  while (++j < ITEMNBR && (i = -1) == -1)
    while (++i < (int)item->item[j])
      {
	*written += snprintf(buff + *written, MSG_LEN - *written,
			     " %s", item_name[j]);
	if (!check_overflow(written, buff, fd))
	  return (false);
      }
  return (true);
}

static int	change_offset(enum dir dir, t_position *off, int *line, int saw)
{
  if (saw + 1 == *line)
    {
      if (dir == UP || dir == DOWN)
	{
	  off->x += (dir == UP) ? -(*line / 2 + 1) : *line / 2 + 1;
	  off->y += (dir == UP) ? -1 : 1;
	}
      else if (dir == RIGHT || dir == LEFT)
	{
	  off->x += (dir == RIGHT) ? 1 : -1;
	  off->y += (dir == RIGHT) ? -(*line / 2 + 1) : *line / 2 + 1;
	}
      *line = pow(sqrt(*line) + 1, 2);
      return (1);
    }
  else
    {
      off->x += (dir == UP) ? 1 : (dir == DOWN) ? -1 : 0;
      off->y += (dir == RIGHT) ? 1 : (dir == LEFT) ? -1 : 0;
    }
  return (0);
}

bool		action_look(t_data *data, t_player *player, UNUSED char *prm)
{
  char		buff[MSG_LEN];
  unsigned int	up;
  int	      	saw;
  t_position	off;
  int		written;
  int		line;

  line = 1;
  saw = 0;
  written = 1;
  buff[0] = '[';
  up = 0;
  off.x = player->pos->x;
  off.y = player->pos->y;
  while (up <= player->level)
    {
      get_real_pos_from(data, &off);
      if (!look_one_case(&data->map[off.y][off.x], &written, buff, player->fd))
	return (false);
      written += snprintf(buff + written, MSG_LEN - written, ",");
      up += change_offset(player->direction, &off, &line, saw);
      ++saw;
    }
  snprintf(buff + written - 1, MSG_LEN - written, " ]\n");
  return (socket_write(player->fd, buff) != -1);
}
