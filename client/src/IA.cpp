//
// IA.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 27 18:50:41 2017 Nathan Scutari
// Last update Fri Jun 30 18:37:56 2017 Nathan Scutari
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

zappy::ICommand	*zappy::IA::tryUp()
{
  Inventory	inv;

  inv = mPlayer->getOwnInventory();
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
  static int	turn = 0;
  ICommand	*choice;

  refreshTile();
  if (++turn == 10)
    {
      turn = 0;
      return (new C_inventory);
    }
  else if (turn == 0 && (choice = tryUp()))
    return (choice);
  choice = mExploration.explore();
  return (choice);
}
