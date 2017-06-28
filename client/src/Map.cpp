//
// Map.cpp for Map in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 17:04:08 2017 vigner_g
// Last update Wed Jun 28 15:37:43 2017 Nathan Scutari
//

#include "Inventory.hpp"
#include "Network.hpp"
#include "Map.hpp"

zappy::Map::Map()
{
}

zappy::Map::~Map()
{
}

std::vector<std::vector<zappy::Inventory> >	&zappy::Map::getGrid()
{
  return (this->grid);
}

void		zappy::Map::setSize(int width, int height)
{
  this->grid.resize(height);
  for (int i = 0; i < height; ++i)
    this->grid[i].resize(width);
}

zappy::Inventory	&zappy::Map::access(int y, int x)
{
  y = (y < 0) ? grid.size() + y : y;
  x = (x < 0) ? grid[0].size() + x : x;
  return (grid[y % grid.size()][x % grid[0].size()]);
}
