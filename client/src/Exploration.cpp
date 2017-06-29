//
// Exploration.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/src
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Jun 29 11:25:53 2017 Nathan Scutari
// Last update Thu Jun 29 14:19:08 2017 Nathan Scutari
//

#include "Exploration.hpp"
#include "C_Look.hpp"

zappy::Exploration::Exploration()
  : path(NULL), mPlayer(NULL)
{

}

zappy::Exploration::~Exploration()
{

}

void	zappy::Exploration::init(Player *player)
{
  mPlayer = player;
}

std::list<t_position>	*zappy::Exploration::getVision()
{
  int			x = 0;
  int			y = 0;
  t_position		relat;
  t_position		tmp;
  std::list<t_position>	*list = new std::list<t_position>;

  tmp.x = mPlayer->getPosition().x;
  tmp.y = mPlayer->getPosition().y;
  list->push_back(tmp);
  for (int i = 0 ; i < mPlayer->getLvl() ; ++i)
    {
      y -= 1;
      x -= 1;
      for (int n = x ; n < 1 + (i + 1) ; ++n)
	{
	  relat.x = n;
	  relat.y = y;
	  tmp = mPlayer->getAbsolutePos(relat);
	  list->push_back(tmp);
	}
    }
  return (list);
}

zappy::ICommand	*zappy::Exploration::needToLook(std::list<t_position> *list)
{
  int	look;
  int	nbr = 0;

  for (std::list<t_position>::iterator it = list->begin() ;
       it != list->end() ; ++it)
    {
      if ((look = mPlayer->getMap().access((*it).y, (*it).x).getLook()) > LOOK_OLD ||
	  look == -1)
	++nbr;
    }
  return ((nbr >= 4 + mPlayer->getLvl()) ? new C_Look : NULL);
}

bool	zappy::Exploration::objectOnSelf() const
{
  if (mPlayer->getMap().access(mPlayer->getPosition().y,
			       mPlayer->getPosition().x).isEmpty())
    return (false);
  return (true);
}

zappy::ICommand	*zappy::Exploration::takeObject()
{
  Inventory	&tile = mPlayer->getMap().access(mPlayer->getPosition().y,
					       mPlayer->getPosition().x);

  return (NULL);
}

zappy::ICommand	*zappy::Exploration::explore()
{
  ICommand		*choice = NULL;

  if (!path && objectOnSelf())
    return (takeObject());
  if ((choice = needToLook(getVision())))
    return (choice);
}
