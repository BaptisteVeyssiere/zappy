/*
** World.h for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/include
**
** Made by Nathan Scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon Jun 19 22:57:24 2017 Nathan Scutari
** Last update Wed Jun 21 20:53:06 2017 vigner_g
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
  };
}

typedef struct	s_position
{
  int		x;
  int		y;
}		t_position;

typedef struct			s_tile
{
  int				time;
  t_position			pos;
  std::map<std::string, int>	items;
}				t_tile;

#endif // !__WORLD_H__
