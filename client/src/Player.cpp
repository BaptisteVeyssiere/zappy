//
// Player.cpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 17:04:08 2017 vigner_g
// Last update Sun Jul  2 17:13:19 2017 Nathan Scutari
//

#include <iostream>
#include <math.h>
#include "Inventory.hpp"
#include "Network.hpp"
#include "Player.hpp"
#include "Exception.hpp"


zappy::Player::Player(World &world)
  : id(0), lvl(1), pos(), facing(0, 1), food(10), OwnInventory(),
    commonInventory(), map(), teamNbPlayer(1), nbOfEgg(0), slot(0),
    leveling(false), mElevation(NULL)
{
  OwnInventory.getInv()["food"] = 10;
  map.setSize(world.width, world.height);
  slot = world.client_num;
}

zappy::Player::~Player()
{

}

void	zappy::Player::init(Elevation *instance)
{
  mElevation = instance;
}

void	zappy::Player::setFood(int nbr)
{
  food = nbr;
  OwnInventory.getInv()["food"] = nbr;
}

void	zappy::Player::SetTeamNbPlayer(int nb)
{
  this->teamNbPlayer = nb;
}

void	zappy::Player::SetId(int nb)
{
  this->id = nb;
}

void	zappy::Player::AddALvl()
{
  this->lvl += 1;
}

zappy::Inventory &zappy::Player::getOwnInventory()
{
  return (this->OwnInventory);
}

std::map<int, zappy::Inventory>	 &zappy::Player::getCommonInventory()
{
  return (this->commonInventory);
}

void		zappy::Player::addToCommonInventory(int lvl, std::string item, int nbr)
{
  this->commonInventory[lvl].addItem(item, nbr);
}

void		zappy::Player::resetCommonInventory()
{
  for (auto it = this->commonInventory.begin(); it != this->commonInventory.end(); it++)
    commonInventory[it->first].reset();
  for (auto it2 = this->OwnInventory.getInv().begin(); it2 != this->OwnInventory.getInv().end(); it2++)
    addToCommonInventory(this->lvl, it2->first, it2->second);
}

t_position	&zappy::Player::getFacing()
{
  return (this->facing);
}

t_position	&zappy::Player::getPosition()
{
  return (this->pos);
}

int		zappy::Player::facingToAngle()
{
  static int		angle[] = {0, 90, 180, 270};
  static t_position	facing[] =
    {
      {0, -1},
      {1, 0},
      {0, 1},
      {-1, 0}
    };


  for (int i = 0 ; i < 4 ; ++i)
    {
      if (getFacing().x == facing[i].x &&
	  getFacing().y == facing[i].y)
	return (angle[i]);
    }
  throw client_exception("Unexpected facing values", __LINE__, __FILE__);
  return (0);
}

t_position	zappy::Player::getAbsolutePos(t_position &relative_pos)
{
  t_position	new_pos;
  int		angle;
  double	cosa;
  double	sina;

  angle = facingToAngle();
  cosa = cos(angle * M_PI / 180);
  sina = sin(angle * M_PI / 180);
  new_pos.x = round(relative_pos.x * cosa - relative_pos.y * sina);
  new_pos.y = round(relative_pos.x * sina + relative_pos.y * cosa);
  new_pos.x += getPosition().x;
  new_pos.y += getPosition().y;
  return (new_pos);
}

zappy::Map	&zappy::Player::getMap()
{
  return (this->map);
}

int		&zappy::Player::getLvl()
{
  return (this->lvl);
}

int		&zappy::Player::getSlot()
{
  return (this->slot);
}

int		&zappy::Player::getFood()
{
  return (food);
}

void		zappy::Player::setLeveling(bool val)
{
  leveling = val;
}

bool		&zappy::Player::getLeveling()
{
  return (leveling);
}

int		zappy::Player::getStoneValue(const std::string &stone) const
{
  return (mElevation->getStoneValue(stone));
}

std::string	&zappy::Player::getToBroadcast()
{
  return (toBroadcast);
}
