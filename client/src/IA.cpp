//
// IA.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 27 18:50:41 2017 Nathan Scutari
// Last update Sun Jul  2 18:26:09 2017 vigner_g
//

#include <iostream>
#include "IA.hpp"
#include "C_inventory.hpp"
#include "C_Fork.hpp"
#include "C_broadcast.hpp"

zappy::IA::IA()
  :egg(0), mPlayer(NULL), mExploration(), mElevation()
{

}

zappy::IA::~IA()
{

}

void	zappy::IA::init(Player *player)
{
  mPlayer = player;
  mExploration.init(player);
  mElevation.init(player);
}

void	zappy::IA::refreshTile()
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
  if (egg < 2)
    {
      ++egg;
      return (new C_Fork);
    }
  else if (!(mPlayer->getToBroadcast().empty()))
    {
      choice = new C_broadcast;
      choice->addArg(mPlayer->getToBroadcast());
      mPlayer->clearToBroadcast();
    }
  else if (!(choice = mElevation.check())) // envoyer des messages et set
    choice = mExploration.explore();
  return (choice);
}
