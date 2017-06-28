//
// Player.cpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 17:04:08 2017 vigner_g
// Last update Wed Jun 28 16:44:05 2017 Nathan Scutari
//

#include "Inventory.hpp"
#include "Network.hpp"
#include "Player.hpp"

zappy::Player::Player(World &world)
  : id(0), lvl(1), food(10), teamNbPlayer(1)
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

  angle = facingToAngle();
  new_pos.x = relative_pos.x * cos(angle * PI / 180);
  new_pos.y = relative_pos.y * sin(angle * PI / 180);
  return (new_pos);
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
