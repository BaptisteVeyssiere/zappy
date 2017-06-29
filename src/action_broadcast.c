/*
** action_broadcast.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Tue Jun 27 16:46:38 2017 Mathis Guilbon
** Last update Wed Jun 28 21:52:40 2017 Mathis Guilbon
*/

#include "server.h"
#include <math.h>

static int	get_shorter(t_data *data, t_position *rec, t_position *inter)
{
  unsigned int	dist[4];
  unsigned int	min;
  int		i;
  int		save;

  i = -1;
  dist[0] = (rec->x - inter[0].x) * (rec->x - inter[0].x) +
    (rec->y - inter[0].y) * (rec->y - inter[0].y);
  dist[1] = (data->width - rec->x - inter[0].x) *
    (data->width - rec->x - inter[0].x) +
    (data->height - rec->y - inter[0].y) * (data->height - rec->y - inter[0].y);
  dist[2] = (rec->x - inter[1].x) * (rec->x - inter[1].x) +
    (rec->y - inter[1].y) * (rec->y - inter[1].y);
  dist[3] = (data->width - rec->x - inter[0].x) *
    (data->width - rec->x - inter[0].x) +
    (data->height - rec->y - inter[0].y) * (data->height - rec->y - inter[0].y);
  min = dist[0];
  save = 0;
  while (++i < 4)
    if (dist[i] < min)
      {
	min = dist[i];
	save = i;
      }
  return (save < 2 ? 0 : 1);
}

/*
**	cercle : (xc, yc), R ==> (x - xc)² + (y - yc)² = R²
**	droite : y = ax + b
**	x²(1 + a²) + x(-2xc + 2ab - 2ayc) + (xc² + yc² + b² - 2byc - R²) = 0
**	X²(1 + a²) + x(2 * (-xc + a * (b - yc))) + (xc² + -R² + (yc - b)(yc - b)) = 0
**
**	if (x >) ceil() else floor();
*/

static void	get_intersection(t_position *src, t_position *rec,
				 t_position *inter)
{
  float		a;
  float		b;
  float		alpha;
  float		beta;
  float		c;
  float		delta;
  float		tmp;
  float		center[2];

  center[0] = rec->x + 0.5;
  center[1] = rec->y + 0.5;
  a = (src->y - center[1]) / (src->x - center[0]);
  b = center[1] - a * center[0];
  fprintf(stderr, "y=%f x + %f\n", a, b);
  alpha = 1 + a * a;
  beta = 2 * (a * (b - center[1]) - center[0]);
  c = center[0] * center[0] +
    (b - center[1]) * (b - center[1]) - 2.25;
  delta = beta * beta - 4 * alpha * c;
  fprintf(stderr, "%f = %f - 4 * %f * %f\n", delta, beta * beta, alpha, c);
  tmp = (-beta - sqrt(delta) / (2 * alpha));
  inter[0].x = (int)tmp;
  inter[0].y = (int)(a * tmp + b);
  tmp = (-beta + sqrt(delta) / (2 * alpha));
  inter[1].x = (int)tmp;
  inter[1].y = (int)(a * tmp + b);
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
    dir[i] = (dir[i - 1] + 1) % CASENBR;
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
  int		shorter;
  int		i;

  get_surrounding(rec, &dir[0], &ward[0]);
  get_intersection(src, rec->pos, &inter[0]);
  shorter = get_shorter(data, rec->pos, &inter[0]);
  print_surrounding_case(rec, &dir[0], &ward[0], &inter[0]);
  i = -1;
  while (++i < CASENBR - 1)
    {
      if (inter[shorter].x == ward[i].x &&
	  inter[shorter].y == ward[i].y)
	{
	  *k = dir[i] + '0';
	  fprintf(stderr, "Signal came from %d\n", dir[i]);
	  i = CASENBR;
	}
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
