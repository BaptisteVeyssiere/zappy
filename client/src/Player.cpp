//
// Player.cpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 17:04:08 2017 vigner_g
// Last update Tue Jun 27 16:31:19 2017 Nathan Scutari
//

#include "Inventory.hpp"
#include "Network.hpp"
#include "Player.hpp"

zappy::Player::Player(World &world)
  : id(0), lvl(1), food(10), teamNbPlayer(1)
{
}

zappy::Player::~Player()
{

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
