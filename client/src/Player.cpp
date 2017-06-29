//
// Player.cpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 17:04:08 2017 vigner_g
// Last update Wed Jun 28 18:39:34 2017 Nathan Scutari
//

#include <iostream>
#include <math.h>
#include "Inventory.hpp"
#include "Network.hpp"
#include "Player.hpp"
#include "Exception.hpp"


zappy::Player::Player(World &world)
  : id(0), lvl(1), pos(), facing(0, 1), food(10), OwnInventory(),
    CommonInventory(), map(), teamNbPlayer(1), nbOfEgg(0), slot(0)
{
  map.setSize(world.width, world.height);
  slot = world.client_num;
}

zappy::Player::~Player()
{

}

void	zappy::Player::setFood(int nbr)
{
  food = nbr;
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

zappy::Inventory &zappy::Player::getSharedInventory()
{
  return (this->CommonInventory);
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
      {-1, 0},
      {0, 1},
      {1, 0},
      {0, -1}
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
