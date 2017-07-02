/*
** action_broadcast_intersection.c for zappy in /home/guilbo_m/rendu/PSU/
**
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
**
** Started on  Sun Jul  2 13:20:22 2017 Mathis Guilbon
** Last update Sun Jul  2 15:38:18 2017 Baptiste Veyssiere
*/

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

  i = -1;
  if (v->x && (float)-c / v->x >= 0 && (float)-c / v->x <= data->height - 1)
    {
      r_inter[++i] = (t_point){0, (float)-c / v->x};
      r_inter[++i] = (t_point){data->width,
			       (float)(v->y * data->width - 1 - c) / v->x};
    }
  else if (v->y && (float)c / v->y >= 0 && (float)c / v->y <= data->width - 1)
    {
      r_inter[++i] = (t_point){(float)c / v->y, 0};
      r_inter[++i] = (t_point){(float)(-v->x * data->height - 1 - c) / -v->y,
			       data->height};
    }

}
