/*
** action_broadcast_intersection.c for zappy in /home/guilbo_m/rendu/PSU/
**
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
**
** Started on  Sun Jul  2 13:20:22 2017 Mathis Guilbon
** Last update Mon Jul  3 18:57:52 2017 Nathan Scutari
*/

#include <string.h>
#include <math.h>
#include "server.h"

void		get_inter(float x, float y, t_position *inter, t_position *ward)
{
  int		i;

  if (y > (float)ward[0].y && x < (float)ward[4].x)
    x = ceilf(x);
  if (y < (float)ward[6].y && x < (float)ward[2].x)
    y = ceilf(y);
  i = -1;
  while (++i < CASENBR - 2 && !((int)x == ward[i].x && (int)y == ward[i].y));
  inter[0] = (t_position){ward[i].x, ward[i].y};
  i = (i + (CASENBR - 1) / 2) % (CASENBR - 1);
  inter[1] = (t_position){ward[i].x, ward[i].y};
}

void		calc_intersection(t_position *src, t_position *rec,
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

void		get_map_inter(t_data *data, t_position *v,
			      t_point *r_inter, int c)
{
  int		i;
  float		res;

  i = -1;
  memset(r_inter, 0, 2 * sizeof(*r_inter));
  if (v->x)
    {
      res = (float)-c / v->x;
      if (res >= 0 && res <= (float)(data->height - 1))
	r_inter[++i] = (t_point){0, res};
      res = ((float)v->y * (data->width - 1) - c) / v->x;
      if (res >= 0 && res <= (float)(data->height - 1))
	r_inter[++i] = (t_point){data->width - 1, res};
    }
  if (v->y)
    {
      res = (float)c / v->y;
      if (v->y && res >= 0 && res <= (float)(data->width - 1))
	r_inter[++i] = (t_point){(float)c / v->y, 0};
      res = ((float)(-v->x) * (data->height - 1) - c) / -v->y;
      if (v->y && res >= 0 && res <= (float)(data->width - 1))
	r_inter[++i] = (t_point){res, data->height - 1};
    }
}
