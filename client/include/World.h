/*
** World.h for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/include
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon Jun 19 22:57:24 2017 Nathan Scutari
** Last update Wed Jun 28 16:55:54 2017 vigner_g
*/

#ifndef __WORLD_H__
# define __WORLD_H__

#include <map>

namespace	zappy
{
  struct	World
  {
    int		height;
    int		width;
    int		client_num;
  Word()
  : height(10), width(10), client_num(1)
    {}
  };
}

typedef struct	s_position
{
  int		x;
  int		y;

  s_position()
  : x(0), y(0)
  {}
}		t_position;
#endif // !__WORLD_H__
