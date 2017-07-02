/*
** action_broadcast.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
**
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
**
** Started on  Tue Jun 27 16:46:38 2017 Mathis Guilbon
** Last update Sun Jul  2 19:12:19 2017 Mathis Guilbon
*/

#include <math.h>
#include <stdio.h>
#include "server.h"

static void	get_surrounding(t_player *rec, char *dir, t_position *ward)
{
  int		i;

  dir[0] = TOP_LEFT;
  i = 0;
  while (++i < UNKNOWN && i != (int)rec->direction)
    dir[0] += 2;
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

static int	get_shorter(t_data *data, t_position *src,
			    t_position *rec, t_position *inter)
{
  t_position	v;
  t_point	r_inter[2];
  unsigned int	dist[4];
  int		shorter;

  v = (t_position){rec->x - src->x, rec->y - src->y};
  dist[0] = v.x * v.x + v.y * v.y;
  fprintf(stderr, "ax+by+c=0||%d * x + %d * y + %d = 0\n", -v.y, v.x, -(-v.y * rec->x + v.x * rec->y));
  get_map_inter(data, &v, &r_inter[0], -(-v.y * rec->x + v.x * rec->y));
  dist[1] = (r_inter[1].x - r_inter[0].x) * (r_inter[1].x - r_inter[0].x) +
    (r_inter[1].y - r_inter[0].y) * (r_inter[1].y - r_inter[0].y);
  fprintf(stderr, "dist[1]:%f\n", sqrt(dist[0]));
  fprintf(stderr, "dist[2]:%f\n", sqrt(dist[1]));
  dist[2] = (src->x - inter[0].x) * (src->x - inter[0].x) +
    (src->y - inter[0].y) * (src->y - inter[0].y);
  dist[3] = (src->x - inter[1].x) * (src->x - inter[1].x) +
    (src->y - inter[1].y) * (src->y - inter[1].y);
  shorter = (dist[2] < dist[3]) ? 0 : 1;
  if (sqrt(dist[0]) > sqrt(dist[1]) / 2)
    shorter = (shorter + 1) % 2;
  fprintf(stderr, "dist[3]:%u\n", dist[2]);
  fprintf(stderr, "dist[4]:%u\nshorter %d", dist[3], shorter + 1);
  return (shorter);
}

static void  print_surrounding_case(t_player *rec, char *dir, t_position *ward, t_position *inter) 
{ 
  fprintf(stderr, "[%d]:(%d,%d)\t[%d]:(%d,%d)\t[%d]:(%d,%d)\n" 
    "[%d]:(%d,%d)\t{%d,%d}\t\t[%d]:(%d,%d)\n" 
    "[%d]:(%d,%d)\t[%d]:(%d,%d)\t[%d]:(%d,%d)\n", 
    dir[0], ward[0].x, ward[0].y, 
    dir[1], ward[1].x, ward[1].y, 
    dir[2], ward[2].x, ward[2].y, 
    dir[7], ward[7].x, ward[7].y, 
    rec->pos->x, rec->pos->y, 
    dir[3], ward[3].x, ward[3].y, 
    dir[6], ward[6].x, ward[6].y, 
    dir[5], ward[5].x, ward[5].y, 
    dir[4], ward[4].x, ward[4].y); 
  fprintf(stderr, "intersection:\n" 
    "\t1:[%d,%d]\n" 
    "\t2:[%d,%d]\n", 
    inter[0].x, inter[0].y, 
    inter[1].x, inter[1].y); 
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
  print_surrounding_case(rec, &dir[0], &ward[0], &inter[0]);
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
