//
// IA.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 27 18:50:41 2017 Nathan Scutari
// Last update Sat Jul  1 00:22:27 2017 Nathan Scutari
//

#include <iostream>
#include "IA.hpp"
#include "C_inventory.hpp"

zappy::IA::IA()
{

}

zappy::IA::~IA()
{

}

void	zappy::IA::init(Player *player)
{
  mPlayer = player;
  mExploration.init(player);
}

zappy::ICommand *zappy::IA::refreshTile()
{
  int	width;
  int	height;

  height = mPlayer->getMap().getGrid().size();
  width = mPlayer->getMap().getGrid()[0].size();
  for (int y = 0 ; y < height ; ++y)
    {
      for (int x = 0 ; x < width ; ++x)
	{
	  mPlayer->getMap().access(y, x).addLook();
	}
    }
}

zappy::ICommand	*zappy::IA::makeAChoice()
{
  ICommand	*choice;

  refreshTile();
  if (!(choice = mElevation.check()))
    choice = mExploration.explore();
  return (choice);
}
