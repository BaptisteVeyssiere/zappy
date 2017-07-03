//
// Join.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Sun Jul  2 16:55:11 2017 Nathan Scutari
// Last update Mon Jul  3 18:12:07 2017 Nathan Scutari
//

#include <unistd.h>
#include "Join.hpp"
#include "C_Forward.hpp"
#include "C_TurnRight.hpp"
#include "C_TurnLeft.hpp"
#include "C_broadcast.hpp"
#include <iostream>

zappy::Join::Join()
  :mPlayer(NULL), waiting(false)
{

}

zappy::Join::~Join()
{

}

void	zappy::Join::init(Player *player)
{
  mPlayer = player;
}

zappy::ICommand	*zappy::Join::getOrientation()
{
  std::string		arg = "void";
  static int	right_dirs[] = {7, 6, 5};
  static int	left_dirs[] = {3, 4};


  for (int i = 0 ; i < 3 ; ++i)
    {
      if (right_dirs[i] == mPlayer->getRegroup().getDirection())
	{
	  mPlayer->getRegroup().setDirection(9);
	  return (new C_TurnRight);
	}
      else if (i < 2 && left_dirs[i] == mPlayer->getRegroup().getDirection())
	{
	  mPlayer->getRegroup().setDirection(9);
	  return (new C_TurnLeft);
	}
    }
  mPlayer->getRegroup().setDirection(9);
  return (NULL);
}

zappy::ICommand	*zappy::Join::followBroadcast()
{
  static int	timeout = 30;
  static bool	split = false;
  std::string	fill = "void";
  std::string	arg = "waiting incantation";
  ICommand	*choice;

  if (mPlayer->getRegroup().getDirection() == 9)
    {
      if (mPlayer->getRegroup().getElevTimeout() <= 0)
	mPlayer->getRegroup().setJoining(-1);
      choice = new C_broadcast;
      choice->addArg(fill);
      return (choice);
    }
  mPlayer->getRegroup().setElevTimeout(30);
  if (split)
    {
      mPlayer->getRegroup().setDirection(9);
      split = false;
      choice = new C_broadcast;
      choice->addArg(fill);
      return (choice);
    }
  split = true;
  std::cout << "Direction: " << mPlayer->getRegroup().getDirection() << std::endl;
  if (mPlayer->getRegroup().getDirection() == 0 &&
      waiting == false)
    {
      timeout = 30;
      waiting = true;
      return (mPlayer->here());
    }
  else if (waiting)
    {
      --timeout;
      if (timeout <= 0)
	{
	  waiting = false;
	  mPlayer->getRegroup().setJoining(-1);
	}
      choice = new C_broadcast;
      choice->addArg(arg);
      return (choice);
    }
  waiting = false;
  if ((choice = getOrientation()))
    return (choice);
  return (new C_Forward);
}

zappy::ICommand	*zappy::Join::join()
{
  ICommand	*choice;

  if (!mPlayer->getToBroadcast().empty())
    {
      choice = new C_broadcast;
      choice->addArg(mPlayer->getToBroadcast());
      mPlayer->getToBroadcast().clear();
      mPlayer->getRegroup().setElevTimeout(30);
      return (choice);
    }
  std::cout << mPlayer->getRegroup().getJoining() << std::endl;
  if (mPlayer->getRegroup().getJoining() == -1)
    return (NULL);
  return (followBroadcast());
}

void	zappy::Join::setWaiting(bool wait)
{
  waiting = wait;
}

zappy::Join	*zappy::Join::getInstance()
{
  return (this);
}
