//
// test.cpp for test in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Wed Jun 28 16:52:34 2017 Nathan Scutari
// Last update Thu Jun 29 12:16:17 2017 Nathan Scutari
//

#include <iostream>
#include <list>
#include "World.h"
#include "Player.hpp"
#include "Exploration.hpp"

int	main(int ac, char **av)
{
  zappy::World		data;
  zappy::Player	*player;
  t_position	pos;
  zappy::Exploration	explore;
  std::list<t_position>	*list;

  data.width = 10;
  data.height = 10;
  data.client_num = 2;
  player = new zappy::Player(data);
  explore.init(player);
  for (int x = 1 ; x < 8 ; ++x)
    player->AddALvl();
  list = explore.getVision();
  for (std::list<t_position>::iterator it = list->begin() ;
	 it != list->end() ; ++it)
    {
      std::cout << (*it).y << " - " << (*it).x << std::endl;
    }
  return (0);
}
