/*
** action_broadcast.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Tue Jun 27 16:46:38 2017 Mathis Guilbon
** Last update Wed Jun 28 18:48:47 2017 Mathis Guilbon
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
*/

static void	get_intersection(t_position *src, t_position *rec,
				 t_position *inter)
{
  float		a;
  float		b;
  float		A;
  float		B;
  float		C;
  float		delta;
  float		tmp;

  a = (float)(rec->y - src->y) / (rec->x - src->x);
  b = src->y - a * src->x;
  A = 1 + a * a;
  B = 2 * (a * (b - (src->y - 0.5)) - (src->x - 0.5));
  C = (src->x - 0.5) * (src->x - 0.5) +
    (b - (src->y - 0.5)) * (b - (src->y - 0.5)) - 1.5 * 1.5;
  delta = B * B - 4 * A * C;
  tmp = (-B - sqrt(delta) / (2 * A));
  inter[0].x = (int)tmp;
  inter[0].y = (int)(a * tmp + b);
  tmp = (-B + sqrt(delta) / (2 * A));
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
    dir[i] = dir[i - 1] % CASENBR;
  ward[0] = (t_position){src->pos->y, src->pos->x - 1};
  ward[1] = (t_position){src->pos->y - 1, src->pos->x};
  ward[2] = (t_position){src->pos->y - 1, src->pos->x + 1};
  ward[3] = (t_position){src->pos->y, src->pos->x + 2};
  ward[4] = (t_position){src->pos->y + 1, src->pos->x + 2};
  ward[5] = (t_position){src->pos->y + 2, src->pos->x + 1};
  ward[6] = (t_position){src->pos->y + 2, src->pos->x};
  ward[7] = (t_position){src->pos->y - 1, src->pos->x - 1};
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
  i = -1;
  while (++i < CASENBR - 1)
    {
      if (inter[shorter].x == ward[i].x &&
	  inter[shorter].y == ward[i].y)
	{
	  *k = dir[i] + '0';
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
