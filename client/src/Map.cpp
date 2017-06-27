//
// Map.cpp for Map in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 17:04:08 2017 vigner_g
// Last update Tue Jun 27 16:26:20 2017 Nathan Scutari
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
