/*
** action_broadcast.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
**
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
**
** Started on  Tue Jun 27 16:46:38 2017 Mathis Guilbon
** Last update Sat Jul  1 18:04:55 2017 Mathis Guilbon
*/

#include <math.h>
#include <stdio.h>
#include "server.h"

static void	get_inter(float x, float y, t_position *inter, t_position *ward)
{
  int		i;

  fprintf(stderr, "float inter[1]:(%f,%f)\n", x, y);
  if (y > (float)ward[0].y && x < (float)ward[4].x)
    x = ceilf(x);
  if (y < (float)ward[6].y && x < (float)ward[2].x)
    y = ceilf(y);
  fprintf(stderr, "int inter[1]:(%d,%d)\n", (int)x, (int)y);
  i = -1;
  while (++i < CASENBR - 2 && !((int)x == ward[i].x && (int)y == ward[i].y));
  inter[0] = (t_position){ward[i].x, ward[i].y};
  i = (i + (CASENBR - 1) / 2) % (CASENBR - 1);
  inter[1] = (t_position){ward[i].x, ward[i].y};
}

static void	calc_intersection(t_position *src, t_position *rec,
				  t_position *inter, t_position *ward)
{
  float		a;
  float		b;
  float		c;
  float		alpha;
  float		beta;
  float		delta;
  float		center[2];

  center[0] = rec->x + 0.5;
  center[1] = rec->y + 0.5;
  if (src->x + 0.5 - center[0] == 0)
    get_inter(center[0] - 0.5, center[1] - 1.5, inter, ward);
  else
    {
      a = (src->y + 0.5 - center[1]) / (src->x + 0.5 - center[0]);
      b = center[1] - a * center[0];
      alpha = 1 + a * a;
      beta = 2 * (a * (b - center[1]) - center[0]);
      c = center[0] * center[0] + (b - center[1]) * (b - center[1]) - 2.25;
      delta = beta * beta - 4 * alpha * c;
      center[0] = (-beta - sqrtf(delta)) / (2 * alpha);
      get_inter(center[0], a * center[0] + b, inter, ward);
    }
}

static void	get_surrounding(t_player *rec, char *dir, t_position *ward)
{
  int		i;

  dir[0] = TOP_LEFT;
  i = 0;
  while (++i < UNKNOWN && i != (int)rec->direction)
    dir[0] += 2;
  fprintf(stderr, "orientation receveur %d coin-gauche %d\n",
	  rec->direction, dir[0]);
  i = 0;
  while (++i < CASENBR - 1)
    dir[i] = (dir[i - 1] - 1 > 0) ? dir[i - 1] - 1 : CASENBR - 1;
  ward[0] = (t_position){rec->pos->x - 1, rec->pos->y};
  ward[1] = (t_position){rec->pos->x, rec->pos->y - 1};
  ward[2] = (t_position){rec->pos->x + 1, rec->pos->y - 1};
  ward[3] = (t_position){rec->pos->x + 2, rec->pos->y};
  ward[4] = (t_position){rec->pos->x + 2, rec->pos->y + 1};
  ward[5] = (t_position){rec->pos->x + 1, rec->pos->y + 2};
  ward[6] = (t_position){rec->pos->x, rec->pos->y + 2};
  ward[7] = (t_position){rec->pos->x - 1, rec->pos->y + 1};
}

static int	get_shorter(t_data *data, t_position *src, t_position *rec, t_position *inter)
{
  int		c;
  int		i;
  t_point	r_inter[2];
  t_position	v;
  unsigned int	dist[4];
  int		shorter;

  i = -1;
  v = (t_position){rec->x - src->x, rec->y - src->y};
  dist[0] = v.x * v.x + v.y * v.y;
  c = -(-v.y * rec->x + v.x * rec->y);
  // y = ax + b   ax + by + c = 0
  // -v.y * x + v.x * y + c = 0;
  fprintf(stderr, "ax+by+c=0||%d * x + %d * y + %d = 0\n", -v.y, v.x, c);
  // x = 0 && x = 10
  if (v.x && (float)-c / v.x >= 0 && (float)-c / v.x <= data->height - 1)
    {
      r_inter[++i] = (t_point){0, (float)-c / v.x};
      r_inter[++i] = (t_point){data->width, (float)(v.y * data->width - 1 - c) / v.x};
    }
  else if (v.y && (float)c / v.y >= 0 && (float)c / v.y <= data->width - 1)
    {
      // y = 0 && y = 10
      r_inter[++i] = (t_point){(float)c / v.y, 0};
      r_inter[++i] = (t_point){(float)(-v.x * data->height - 1 - c) / -v.y, data->height};
    }
  dist[1] = (r_inter[1].x - r_inter[0].x) * (r_inter[1].x - r_inter[0].x) +
    (r_inter[1].y - r_inter[0].y) * (r_inter[1].y - r_inter[0].y);
  fprintf(stderr, "dist[1]:%f\nnb inter %d\n", sqrt(dist[0]), i);
  fprintf(stderr, "dist[2]:%f\n", sqrt(dist[1]));
  dist[2] = (src->x - inter[0].x) * (src->x - inter[0].x) +
    (src->y - inter[0].y) * (src->y - inter[0].y);
  dist[3] = (src->x - inter[1].x) * (src->x - inter[1].x) +
    (src->y - inter[1].y) * (src->y - inter[1].y);
  shorter = (dist[2] < dist[3]) ? 0 : 1;
  /*  if (dist[1] < dist[0])*/
  if (sqrt(dist[0]) > sqrt(dist[1]) / 2)
    shorter = (shorter + 1) % 2; 
  fprintf(stderr, "dist[3]:%u\n", dist[2]);
  fprintf(stderr, "dist[4]:%u\n", dist[3]);
  return (shorter);
}

static void	get_message_dir(t_data *data, t_position *src,
				t_player *rec, char *k)
{
  char		dir[CASENBR - 1];
  t_position	ward[CASENBR - 1];
  t_position	inter[2];
  int		shorter;
  int		i;

  get_surrounding(rec, &dir[0], &ward[0]);
  calc_intersection(src, rec->pos, &inter[0], &ward[0]);
  shorter = get_shorter(data, src, rec->pos, &inter[0]);
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
  if (pbc(data, player, prm) == -1)
    return (false);
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