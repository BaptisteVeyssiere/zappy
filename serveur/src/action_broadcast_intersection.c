/*
** action_broadcast_intersection.c for zappy in /home/guilbo_m/rendu/PSU/
**
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
**
** Started on  Sun Jul  2 13:20:22 2017 Mathis Guilbon
** Last update Sun Jul  2 20:01:30 2017 Mathis Guilbon
*/

#include <string.h>
#include <stdio.h>
#include <math.h>
#include "server.h"

void		get_inter(float x, float y, t_position *inter, t_position *ward)
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

void		calc_intersection(t_position *src, t_position *rec,
				  t_position *inter, t_position *ward)
{
  float		a;
  float		b;
  float		c;
  float		alpha;
  float		beta;
  float		delta;
  t_point	center;

  center.x = rec->x + 0.5;
  center.y = rec->y + 0.5;
  if (src->x + 0.5 - center.x == 0)
    get_inter(center.x - 0.5, center.y - 1.5, inter, ward);
  else
    {
      a = (src->y + 0.5 - center.y) / (src->x + 0.5 - center.x);
      b = center.y - a * center.x;
      alpha = 1 + a * a;
      beta = 2 * (a * (b - center.y) - center.x);
      c = center.x * center.x + (b - center.y) * (b - center.y) - 2.25;
      delta = beta * beta - 4 * alpha * c;
      center.x = (-beta - sqrtf(delta)) / (2 * alpha);
      get_inter(center.x, a * center.x + b, inter, ward);
    }
}

void		get_map_inter(t_data *data, t_position *v,
			      t_point *r_inter, int c)
{
  int		i;
  float		res;
  
  i = -1;
  memset(r_inter, 0, 2 * sizeof(*r_inter));
  fprintf(stderr, "c= %d\nv(%d,%d)\n", c, v->x, v->y);
  if (v->x)
    {
      res = (float)-c / v->x;
      fprintf(stderr, "x=0 (%f,%f)\n", 0.0, res);
      if (res >= 0 && res <= (float)(data->height - 1))
	r_inter[++i] = (t_point){0, res};
      res = ((float)v->y * (data->width - 1) - c) / v->x;
      fprintf(stderr, "x=9 (%f,%f)\n", (float)data->width - 1, res);
      if (res >= 0 && res <= (float)(data->height - 1))
	r_inter[++i] = (t_point){data->width - 1, res};
    }
  if (v->y)
    {
      res = (float)c / v->y;
      fprintf(stderr, "y=0 (%f,%f)\n", res, 0.0);
      if (res >= 0 && res <= (float)(data->width - 1))
	r_inter[++i] = (t_point){(float)c / v->y, 0};
      res = ((float)v->x * (data->height - 1) - c) / v->y;
      fprintf(stderr, "y=9 (%f,%f)\n", res, (float)data->height - 1);
      if (res >= 0 && res <= (float)(data->width - 1))
	r_inter[++i] = (t_point){res, data->height - 1};
    }
  fprintf(stderr, "inter[1]:(%f,%f)\ninter[2]:(%f,%f)\n", r_inter[0].x, r_inter[0].y, r_inter[1].x, r_inter[1].y);
}
