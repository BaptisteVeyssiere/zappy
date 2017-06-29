/*
** action_broadcast.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
**
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
**
** Started on  Tue Jun 27 16:46:38 2017 Mathis Guilbon
** Last update Thu Jun 29 16:44:28 2017 Mathis Guilbon
*/

#include <math.h>
#include <stdio.h>
#include "server.h"


static void	get_inter(float x, float y, t_position *inter, t_position *ward)
{
  int		i;
  int		k;

  k = 0;
  i = -1;
  fprintf(stderr, "float inter[1]:(%f,%f)\n", x, y);
  while (++i < CASENBR - 3)
    if (x >= (float)ward[i].x && x <= (float)ward[i + 1].x &&
	y >= (float)ward[i].y && y <= (float)ward[i + 1].y)
      {
	k = i;
	i = CASENBR;
      }
  k = (i == CASENBR) ? k : CASENBR - 2;
  inter[0] = (t_position){ward[k].x, ward[k].y};
  k = (k + (CASENBR - 1) / 2) % (CASENBR - 1);
  inter[1] = (t_position){ward[k].x, ward[k].y};
}

static void	calc_intersection(t_position *src, t_position *rec,
				  t_position *inter, t_position *ward)
{
  float		a;
  float		b;
  float		alpha;
  float		beta;
  float		c;
  float		delta;
  float		center[2];

  center[0] = rec->x + 0.5;
  center[1] = rec->y + 0.5;
  if (src->x + 0.5 - center[0])
    a = (src->y + 0.5 - center[1]) / (src->x + 0.5 - center[0]);
  else
    a = 0.0;
  b = center[1] - a * center[0];
  fprintf(stderr, "y=%f x + %f\n", a, b);
  alpha = 1 + a * a;
  beta = 2 * (a * (b - center[1]) - center[0]);
  c = center[0] * center[0] +
    (b - center[1]) * (b - center[1]) - 2.25;
  delta = beta * beta - 4 * alpha * c;
  fprintf(stderr, "%f = %f - 4 * %f * %f\n", delta, beta * beta, alpha, c);
  center[0] = (-beta - sqrt(delta)) / (2 * alpha);
  center[1] = a * center[0] + b;
  get_inter(center[0], center[1], inter, ward);
}

static void	get_surrounding(t_player *src, char *dir, t_position *ward)
{
  int		i;

  dir[0] = TOP_LEFT;
  i = 0;
  while (++i < UNKNOWN && i != (int)src->direction)
    dir[0] += 2;
  i = 0;
  while (++i < CASENBR - 1)
    dir[i] = dir[i - 1] % (CASENBR - 1) + 1;
  ward[0] = (t_position){src->pos->x - 1, src->pos->y - 1};
  ward[1] = (t_position){src->pos->x, src->pos->y - 2};
  ward[2] = (t_position){src->pos->x + 1, src->pos->y - 2};
  ward[3] = (t_position){src->pos->x + 2, src->pos->y - 1};
  ward[4] = (t_position){src->pos->x + 2, src->pos->y};
  ward[5] = (t_position){src->pos->x + 1, src->pos->y + 1};
  ward[6] = (t_position){src->pos->x, src->pos->y + 1};
  ward[7] = (t_position){src->pos->x - 1, src->pos->y};
}

static void	get_message_dir(t_data *data, t_position *src,
				t_player *rec, char *k)
{
  char		dir[CASENBR - 1];
  t_position	ward[CASENBR - 1];
  t_position	inter[2];
  unsigned int	dist[2];
  int		shorter;
  int		i;

  get_surrounding(rec, &dir[0], &ward[0]);
  calc_intersection(src, rec->pos, &inter[0], &ward[0]);
  dist[0] = (rec->pos->x - src->x) * (rec->pos->x - src->x) +
    (rec->pos->y - src->y) * (rec->pos->y - src->y);
  dist[1] = (data->width - rec->pos->x - src->x) *
    (data->width - rec->pos->x - src->x) +
    (data->height - rec->pos->y - src->y) *
    (data->height - rec->pos->y - src->y);
  shorter = (dist[1] < dist[0]) ? 1 : 0;
  shorter = (src->x > rec->pos->x) ? (shorter + 1) % 2 : shorter;
  fprintf(stderr, "dist[%d]:%u\n", 0, dist[0]);
  fprintf(stderr, "dist[%d]:%u\n", 1, dist[1]);
  print_surrounding_case(rec, &dir[0], &ward[0], &inter[0]);
  i = -1;
  while (++i < CASENBR - 1)
    if (inter[shorter].x == ward[i].x &&
	inter[shorter].y == ward[i].y)
      {
	*k = dir[i] + '0';
	i = CASENBR;
      }
}

bool		action_broadcast(t_data *data, t_player *player, char *prm)
{
  char		buff[MSG_LEN];
  t_player	*tmp;

  tmp = data->players_root;
  snprintf(buff, MSG_LEN, "message 0, %s\n", prm);
  while (tmp != NULL)
    {
      if (tmp != player)
	{
	  if (!(player->pos->x == tmp->pos->x &&
		player->pos->y == tmp->pos->y))
	    get_message_dir(data, player->pos, tmp, &buff[8]);
	  else
	    buff[8] = '0';
	  if (socket_write(tmp->fd, buff) == -1)
	    return (false);
	}
      tmp = tmp->next;
    }
  return (socket_write(player->fd, "ok\n") != -1);
}
