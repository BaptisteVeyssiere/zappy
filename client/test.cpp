//
// test.cpp for test in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Wed Jun 28 16:52:34 2017 Nathan Scutari
// Last update Fri Jun 30 16:00:18 2017 Nathan Scutari
//

#include <iostream>
#include <list>
#include "World.h"
#include "Player.hpp"
#include "Exploration.hpp"
#include "C_Forward.hpp"
#include "ICommand.hpp"

int	main(int ac, char **av)
{
  zappy::tileValue	tile;
  zappy::World	info;
  zappy::Player	*player;
  zappy::Exploration	exploration;

  info.width = 10;
  info.height = 10;
  info.client_num = 2;
  player = new zappy::Player(info);
  exploration.init(player);
  tile.pos.x = -1;
  tile.pos.y = 1;
  exploration.moveToPos(tile);
  while (!tile.path.empty())
    {
      if (tile.path.front()->getStr() == "Forward")
	std::cout << "Forward" << std::endl;
      else if (tile.path.front()->getStr() == "Right")
	std::cout << "Right"  << std::endl;
      else
	std::cout << "Left" << std::endl;
      tile.path.pop();
    }
  return (0);
}
