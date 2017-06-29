//
// Exploration.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/src
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Jun 29 11:25:53 2017 Nathan Scutari
// Last update Thu Jun 29 19:15:32 2017 Nathan Scutari
//

#include "Exploration.hpp"
#include "C_Look.hpp"
#include "C_Forward.hpp"
#include "C_TurnRight.hpp"
#include "C_TurnLeft.hpp"
#include "C_Take.hpp"

zappy::Exploration::Exploration()
  : path(), mPlayer(NULL)
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
  ICommand	*choice = new C_Take;
  Inventory	&tile = mPlayer->getMap().access(mPlayer->getPosition().y,
					       mPlayer->getPosition().x);

  if (tile.getInv().find("food") != tile.getInv().end())
    {
      choice->addArg("food");
      return (choice);
    }
  for (std::map<std::string, int>::iterator it = tile.getInv().begin() ;
       it != tile.getInv().end() ; ++it)
    {
      if (it->second > 0)
	{
	  choice->addArg(it->first);
	  return (choice);
	}
    }

  delete choice;
  return (NULL);
}

std::list<t_position>	*zappy::Exploration::getNearbyPos()
{
  t_position	relat;
  t_position	tmp;
  std::list<t_position>	*list = new std::list<t_position>;

  for (int y = -2 ; y < 3 ; ++y)
    {
      for (int x = -2 ; x < 3 ; ++x)
	{
	  relat.y = y;
	  relat.x = x;
	  tmp = mPlayer->getAbsolutePos(relat);
	  list->push_back(tmp);
	}
    }
  return (list);
}

int			zappy::Exploration::foodValue()
{
  int	food = mPlayer->getFood();

  if (food < 5)
    return (10);
  else if (food < 20)
    return (4);
  return (1);
}

void			zappy::Exploration::fillOrientations(t_position &pos,
							     t_position &dest,
							     bool orient[4])
{
  orient[0] = true;
  if (dest.y > pos.y)
    {
      orient[2] = true;
      orient[0] = false;
    }
  orient[3] = true;
  if (dest.x > pos.x)
    {
      orient[1] = true;
      orient[3] = false;
    }
}

int			zappy::Exploration::getRightOrientation(zappy::tileValue &tile,
								t_position &pos,
								t_position &dest)
{
  int	angle;
  bool	orientations[4] = {false};
  int	playerAngle = mPlayer->facingToAngle();

  fillOrientations(pos, dest, orientations);
  if (orientations[playerAngle / 90] == true)
    return (playerAngle);
  if (orientations[angle = playerAngle + 90 % 360] == true)
    tile.path.push(new C_TurnRight);
  else if (orientations[angle = (playerAngle - 90) < 0 ? 270 : playerAngle - 90]
	   == true)
    tile.path.push(new C_TurnLeft);
  else
    {
      angle = playerAngle + 180 % 360;
      tile.path.push(new C_TurnLeft);
      tile.path.push(new C_TurnLeft);
    }
  return (angle);
}

void			zappy::Exploration::getOrientation(zappy::tileValue &tile,
							   t_position &pos,
							   t_position &dest,
							   int angle)
{
  if (angle == 0 || angle == 180)
    {
      if (dest.x > pos.x && angle == 0)
	tile.path.push(new C_TurnRight);
      else if (dest.x < pos.x && angle == 180)
	tile.path.push(new C_TurnRight);
      else
	tile.path.push(new C_TurnLeft);
    }
  else if (angle == 90 || angle == 270)
    {
      if (dest.y > pos.y && angle == 90)
	tile.path.push(new C_TurnRight);
      else if (dest.y < pos.y && angle == 270)
	tile.path.push(new C_TurnRight);
      else
	tile.path.push(new C_TurnLeft);
    }
}

void			zappy::Exploration::moveToDest(zappy::tileValue &tile,
						       t_position &pos,
						       t_position &dest,
						       t_position &tmp)
{
  if (tmp.x == dest.x)
    {
      while (pos.y != dest.y)
	{
	  tile.path.push(new C_Forward);
	  if (pos.y > dest.y)
	    --pos.y;
	  else
	    ++pos.y;
	}
    }
  else
    {
      while (pos.x != dest.x)
	{
	  tile.path.push(new C_Forward);
	  if (pos.x > dest.x)
	    --pos.x;
	  else
	    ++pos.x;
	}
    }
}

void			zappy::Exploration::moveToPos(zappy::tileValue &tile)
{
  t_position			tmp;
  t_position			pos = mPlayer->getPosition();
  t_position			dest = tile.pos;
  int				new_angle;

  if (pos.x == dest.x && pos.y == dest.y)
    return ;
  new_angle = getRightOrientation(tile, pos, dest);
  tmp = pos;
  while (tmp.x != dest.x && tmp.y != dest.y)
    {
      if (new_angle == 270)
	tmp.x -= 1;
      else
	tmp.x += 1;
      if (new_angle == 0)
	tmp.y -= 1;
      tile.path.push(new C_Forward);
    }
  if ((tmp.x == dest.x && pos.y == dest.y) ||
      (tmp.y == dest.y && pos.x == dest.x))
    return ;
  getOrientation(tile, pos, dest, new_angle);
  moveToDest(tile, pos, dest, tmp);
}

std::list<zappy::tileValue>	*zappy::Exploration::fillValues(std::list<t_position> *list)
{
  std::map<std::string, int>	tile;
  Inventory			inv;
  tileValue			tmp;
  std::list<tileValue>	*tiles = new std::list<tileValue>(list->size());

  for (std::list<t_position>::iterator it = list->begin() ; it != list->end() ;
       ++it)
    {
      inv = mPlayer->getMap().access((*it).y, (*it).x);
      tile = inv.getInv();
      tmp.value = (inv.getLook() > 0) ? inv.getLook() / 4 : 300;
      for (std::map<std::string, int>::iterator it = tile.begin() ;
	   it != tile.end() ; ++it)
	{
	  if (it->first == "food")
	    tmp.value -= it->second * foodValue();
	  else
	    tmp.value -= it->second;
	  moveToPos(tmp);
	  tmp.value += tmp.path.size();
	  tiles->push_back(tmp);
	}
    }
  return (tiles);
}

void		zappy::Exploration::createPath()
{
  std::list<t_position>	*list;
  std::list<tileValue>	*values;
  tileValue	        tile;

  list = getNearbyPos();
  values = fillValues(list);
  tile = values->front();
  for (std::list<tileValue>::iterator it = values->begin() ; it != values->end() ;
       ++it)
    {
      if (it->value < tile.value)
	tile = *it;
    }
  path = tile.path;
  values->clear();
}

zappy::ICommand	*zappy::Exploration::explore()
{
  ICommand		*choice = NULL;

  if (!path.empty() && objectOnSelf())
    return (takeObject());
  else if (!path.empty())
    {
      choice = path.front();
      path.pop();
      return (choice);
    }
  if ((choice = needToLook(getVision())))
    return (choice);
  createPath();
  if (path.empty())
    return (takeObject());
  choice = path.front();
  path.pop();
  return (choice);
}
