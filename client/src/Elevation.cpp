//
// Elevation.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/src
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 30 23:55:55 2017 Nathan Scutari
// Last update Sat Jul  1 21:26:06 2017 Nathan Scutari
//

#include <iostream>
#include "C_inventory.hpp"
#include "Elevation.hpp"
#include "C_Look.hpp"
#include "C_incantation.hpp"
#include "C_Take.hpp"
#include "C_Set.hpp"

zappy::Elevation::Elevation()
  :requirements(false), elevating(false), mPlayer(NULL)
{

}

zappy::Elevation::~Elevation()
{

}

void	zappy::Elevation::init(Player *player)
{
  mPlayer = player;
}

bool	zappy::Elevation::hasEnough(std::string item, int nbr)
{
  std::cout << item << " - " << nbr << std::endl;
  if (item == "player")
    {
      if (mPlayer->getMap().access(mPlayer->getPosition().y,
				   mPlayer->getPosition().x).getInv()[item] == nbr)
	return (true);
      else
	return (false);
    }
  std::cout << mPlayer->getOwnInventory().getInv()[item] << std::endl;
  if (mPlayer->getOwnInventory().getInv()[item] >= nbr)
    return (true);
  return (false);
}

bool	zappy::Elevation::tryUp()
{
  std::cout << "Checking up" << std::endl;
  for (int i = 0 ; i < 8 ; ++i)
    if (!hasEnough(items[i], required[mPlayer->getLvl()][i]))
      return (false);
  requirements = true;
  std::cout << "I can lvl up ! :-)" << std::endl;
  return (true);
}

zappy::ICommand	*zappy::Elevation::elevate()
{
  ICommand	*choice;

  if (mPlayer->getMap().access(mPlayer->getPosition().y, mPlayer->getPosition().x).
      getLook() >= 10)
    return (new C_Look);
  for (int i = 1 ; i < 7 ; ++i)
    {
      if (mPlayer->getMap().access(mPlayer->getPosition().y,
				   mPlayer->getPosition().x)
	  .getInv()[items[i]] > required[mPlayer->getLvl()][i])
	{
	  std::cout << "Preparing incantation" << std::endl;
	  choice = new C_Take;
	  choice->addArg(items[i]);
	  return (choice);
	}
      else if (mPlayer->getMap().access(mPlayer->getPosition().y,
					mPlayer->getPosition().x)
	       .getInv()[items[i]] < required[mPlayer->getLvl()][i])
	{
	  std::cout << "Preparing incantation" << std::endl;
	  choice = new C_Set;
	  choice->addArg(items[i]);
	  return (choice);
	}
    }
  std::cout << "I'm leveling up! :-)" << std::endl;
  requirements = false;
  return (new C_incantation);
}

zappy::ICommand	*zappy::Elevation::check()
{
  static int	turn = 0;

  if (requirements)
    return (elevate());
  if (++turn == 10)
    {
      turn = 0;
      return (new C_inventory);
    }
  else if (turn == 1)
    return (new C_Look);
  else if (turn == 2 && (tryUp()))
    return (elevate());
  return (NULL);
}
