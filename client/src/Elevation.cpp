//
// Elevation.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/src
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 30 23:55:55 2017 Nathan Scutari
// Last update Mon Jul  3 21:18:35 2017 Nathan Scutari
//

#include <iostream>
#include <math.h>
#include "C_inventory.hpp"
#include "Elevation.hpp"
#include "C_Look.hpp"
#include "C_incantation.hpp"
#include "C_Take.hpp"
#include "C_Set.hpp"
#include "Exception.hpp"
#include "C_broadcast.hpp"

zappy::Elevation::Elevation()
  :requirements(false), elevating(false), mPlayer(NULL), canceled(false)
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
				   mPlayer->getPosition().x).getInv()[item] == 1)
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
  mPlayer->setLeveling(true);
  mPlayer->getRegroup().startElevating();
  mPlayer->stopElev();
  bool	fill = false;
  playersRegrouped(true, fill);
  return (new C_incantation(false));
}

zappy::ICommand	*zappy::Elevation::playersRegrouped(bool reset, bool &requirements)
{
  static bool	come = false;
  static bool	herep = false;
  ICommand	*fill;
  std::string	arg = "waiting confirmation";
  static bool	init = true;
  static bool	free = false;

  if (reset)
    {
      come = false;
      elevating = false;
      return (NULL);
    }
  if (mPlayer->getLvl() == 1 || herep || mPlayer->isElev())
    return (NULL);
  if (init)
    {
      init = false;
      mPlayer->getRegroup().setElevTimeout(ELEVATION_ASKING_TIMEOUT);
      mPlayer->getRegroup().setPlayerNbr(required[mPlayer->getLvl()][7] - 1);
      return (mPlayer->elevation());
    }
  if (static_cast<int>(mPlayer->getRegroup().getIDS().size())
      < required[mPlayer->getLvl()][7] - 1 && !free)
    {
      mPlayer->getRegroup().decElevTimeout();
      if (mPlayer->getRegroup().getElevTimeout() <= 0)
	{
	  init = true;
	  free = false;
	  canceled = true;
	  requirements = false;
	  come = false;
	  return (mPlayer->cancel());
	}
      fill = new C_broadcast;
      fill->addArg(arg);
      return (fill);
    }
  if (!mPlayer->lowestId())
    {
      init = true;
      free = false;
      canceled = true;
      requirements = false;
      come = false;
      return (mPlayer->cancel());
    }
  if (free == false)
    {
      free = true;
      mPlayer->getMap().access(mPlayer->getPosition().y, mPlayer->getPosition().x)
	.getInv()["player"] = 1;
      mPlayer->getRegroup().setElevTimeout(ELEVATION_COMING_TIMEOUT);
    }
  if (mPlayer->getMap().access(mPlayer->getPosition().y, mPlayer->getPosition().x)
      .getInv()["player"] < required[mPlayer->getLvl()][7])
    {
      mPlayer->getRegroup().decElevTimeout();
      if (mPlayer->getRegroup().getElevTimeout() <= 0)
	{
	  init = true;
	  free = false;
	  come = false;
	  canceled = true;
	  requirements = false;
	  return (mPlayer->cancel());
	}
      return (mPlayer->come());
    }
  init = true;
  free = false;
  herep = true;
  come = false;
  std::cout << "player here" << std::endl;
  return (NULL);
}

zappy::ICommand	*zappy::Elevation::check()
{
  static int	turn = 0;
  ICommand	*choice;

  if (canceled)
    {
      canceled = false;
      requirements = false;
      return (new C_inventory);
    }
  if (requirements)
    {
      if ((choice = playersRegrouped(false, requirements)))
	return (choice);
      return (elevate());
    }
  if (++turn == 10)
    {
      turn = 0;
      return (new C_inventory);
    }
  else if (turn == 1)
    return (new C_Look);
  else if (turn == 2 && mPlayer->getLvl() < 8 && mPlayer->lowestId() && (tryUp()))
    return (elevate());
  return (NULL);
}

int		zappy::Elevation::getStoneValue(const std::string &stone) const
{
  if (mPlayer->getLvl() >= 8)
    return (0);
  for (int i = 1 ; i < 7 ; ++i)
    {
      if (items[i] == stone)
	{
	  if (mPlayer->getOwnInventory().getInv()[stone] <
	      required[mPlayer->getLvl()][i])
	    return (3);
	  else
	    return (1);
	}
    }
  throw client_exception("This item does not exist: " + stone, __LINE__, __FILE__);
  return (-1);
}

zappy::Elevation	*zappy::Elevation::getInstance()
{
  return (this);
}
