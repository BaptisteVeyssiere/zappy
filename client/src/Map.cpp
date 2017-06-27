//
// Map.cpp for Map in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 17:04:08 2017 vigner_g
// Last update Tue Jun 27 21:47:25 2017 vigner_g
//

#include "Inventory.hpp"
#include "Network.hpp"
#include "Map.hpp"


#include <iostream>

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

  std::vector<Inventory>	row;
  Inventory			tile;

  std::cout << "width:" << width << "  height:" << height << std::endl;
  for(int y = 0; y < width; ++y)
    {
      std::cout << "test" << std::endl;
      row.push_back(tile);
    }
  for (int i = 0; i < height; ++i)
    {
      std::cout << "test2" << std::endl;
      this->grid.push_back(row);
    }
}
