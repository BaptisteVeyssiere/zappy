//
// Join.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Sun Jul  2 16:55:11 2017 Nathan Scutari
// Last update Sun Jul  2 18:51:30 2017 Nathan Scutari
//

#include "Join.hpp"
#include "C_Forward.hpp"
#include "C_TurnRight.hpp"
#include "C_TurnLeft.hpp"
#include "C_broadcast.hpp"

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
  static int	right_dirs[] = {7, 6, 5};
  static int	left_dirs[] = {3, 4};

  for (int i = 0 ; i < 3 ; ++i)
    {
      if (right_dirs[i] == mPlayer->getRegroup().getDirection())
	return (new C_TurnRight);
      else if (i < 2 && left_dirs[i] == mPlayer->getRegroup().getDirection())
	return (new C_TurnLeft);
    }
  return (NULL);
}

zappy::ICommand	*zappy::Join::followBroadcast()
{
  std::string	arg = "waiting incantation";
  ICommand	*choice;

  if (mPlayer->getRegroup().getDirection() == 0 &&
      waiting == false)
    {
      waiting = true;
      return (mPlayer->here());
    }
  else if (waiting)
    {
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
      return (choice);
    }
  if (mPlayer->getRegroup().getJoining() == -1)
    return (NULL);
  return (followBroadcast());
}
