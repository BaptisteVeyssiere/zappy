//
// test.cpp for test in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Wed Jun 28 16:52:34 2017 Nathan Scutari
// Last update Wed Jun 28 16:59:18 2017 Nathan Scutari
//

#include <iostream>
#include "Player.hpp"

int	main(int ac, char **av)
{
  zappy::World		data;
  zappy::Player	*player;
  t_position	pos;

  data.width = 10;
  data.height = 10;
  data.client_num = 2;
  player = new zappy::Player(data);
  pos.x = -5;
  pos.y = -8;
  std::cout << player->getFacing().x << " - " << player->getFacing().y
	    << std::endl;
  std::cout << player->getAbsolutePos(pos).x << " - "
	    << player->getAbsolutePos(pos).y << std::endl;
  return (0);
}
