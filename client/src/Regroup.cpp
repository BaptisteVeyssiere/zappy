//
// Regroup.cpp for Regroup in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jul  1 22:08:06 2017 vigner_g
// Last update Sun Jul  2 22:18:41 2017 Nathan Scutari
//

#include "Regroup.hpp"

zappy::Regroup::Regroup() : elevating(false), elevTimeout(0),
			    joining(-1), direction(0), ids(),
			    playerNbr()
{
}

zappy::Regroup::~Regroup()
{
}

bool	zappy::Regroup::isElevating()
{
  return (this->elevating);
}

void	zappy::Regroup::startElevating()
{
  this->elevating = true;
}

void	zappy::Regroup::stopElevating()
{
  this->elevating = false;
}

int	zappy::Regroup::getJoining()
{
  return (this->joining);
}

void	zappy::Regroup::setJoining(int id)
{
  this->joining = id;
}

void	zappy::Regroup::stopJoining()
{
  this->joining = -1;
}

int	zappy::Regroup::getDirection()
{
  return (this->direction);
}

void	zappy::Regroup::setDirection(int dir)
{
  this->direction = dir;
}

std::vector<int>	&zappy::Regroup::getIDS()
{
  return (this->ids);
}

void	zappy::Regroup::addID(int id)
{
  this->ids.push_back(id);
}

void	zappy::Regroup::resetIDS()
{
  this->ids.clear();
}

int	zappy::Regroup::howManyFree()
{
  return (this->ids.size());
}

int	zappy::Regroup::getElevTimeout()
{
  return (this->elevTimeout);
}

void	zappy::Regroup::setElevTimeout(int nbr)
{
  this->elevTimeout = nbr;
}

void	zappy::Regroup::decElevTimeout(int nbr)
{
  this->elevTimeout -= nbr;
}

void	zappy::Regroup::setPlayerNbr(int nbr)
{
  this->playerNbr = nbr;
}

int	zappy::Regroup::getPlayerNbr()
{
  return (this->playerNbr);
}
