//
// Player.cpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 17:04:08 2017 vigner_g
// Last update Wed Jun 28 17:01:07 2017 vigner_g
//

#include "Inventory.hpp"
#include "Network.hpp"
#include "Player.hpp"

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

// void	zappy::Player::TurnLeft()
// {
//   this->direction -= 1;
//   direction = (direction < 0) ? 3 : direction;
// }

// void	zappy::Player::TurnRight()
// {
//   this->direction += 1;
//   direction = (direction > 3) ? 0 : direction;
// }

// void	zappy::Player::GoForward()
// {
//   switch (this->direction)
//     {
//     case 0: this->pos.x += 1;
//       break;
//     case 1: this->pos.y += 1;
//       break;
//     case 3: this->pos.x -= 1;
//       break;
//     case 4: this->pos.y -= 1;
//       break;
//     }
// }

// void	zappy::Player::Fork()
// {
// }

// void	zappy::Player::Eject()
// {
// }
