//
// Regroup.cpp for Regroup in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jul  1 22:08:06 2017 vigner_g
// Last update Sat Jul  1 23:48:33 2017 vigner_g
//

#include "Regroup.hpp"

zappy::Regroup::Regroup() : elevating(false), joining(-1), direction(0), ids()
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
