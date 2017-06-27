//
// Map.hpp for map in /home/vigner_g/rendu/PSU_2016_zappy
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Mon Jun 26 15:59:52 2017 vigner_g
// Last update Tue Jun 27 16:59:43 2017 Nathan Scutari
//

#ifndef	__MAP_HPP__
# define __MAP_HPP__

#include <vector>
#include "World.h"
#include <string>
#include "Inventory.hpp"

namespace zappy
{
  class Inventory;
};

namespace zappy
{
  class	Map
  {
  public:
    Map();
    ~Map();

  private:
    Map(Map &other);
    Map	&operator=(Map &other);

  private:
    std::vector<std::vector<Inventory> >	grid;

  public:
    std::vector<std::vector<Inventory> >	&getGrid();
    void					setSize(int width, int height);
  };
}

//std::vector<std::vector<int>> array_2d(rows, std::vector<int>(cols, 0));

#endif // !__MAP_HPP__
