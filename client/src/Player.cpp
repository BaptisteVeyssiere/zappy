//
// Player.cpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 17:04:08 2017 vigner_g
// Last update Wed Jun 21 20:53:49 2017 vigner_g
//

#include "Player.hpp"

zappy::Player::Player(Network *network)
{
  this->pos.x = 0;
  this->pos.y = 0;
}

zappy::Player::~Player()
{
}

void	zappy::Player::ResetCommonInventory()
{
  this->CommonInventory.clear();
  this->CommonInventory = inventory;
}

void	zappy::Player::AddToCommonInventory(std::map<std::string, int> other)
{
  for(auto it = other.begin(); it != other.end(); it++)
    this->CommonInventory[it->first] += it->second;
  other.clear();
}

void	zappy::Player::TurnLeft()
{
  this->direction -= 1;
  direction = (direction < 0) ? 3 : direction;
  //envoyer la commande correspondante au serveur
}

void	zappy::Player::TurnRight()
{
  this->direction += 1;
  direction = (direction > 3) ? 0 : direction;
  //envoyer la commande correspondante au serveur
}

void	zappy::Player::GoForward()
{
  switch (this->direction)
    {
    case 0: this->pos.x += 1;
      break;
    case 1: this->pos.y += 1;
      break;
    case 3: this->pos.x -= 1;
      break;
    case 4: this->pos.y -= 1;
      break;
    }
}

void	zappy::Player::PickupItem(std::string item)
{
  auto it = CommonInventory.find(item);
  if (it != CommonInventory.end()) //ça c'est pas sur
    CommonInventory[it->first] += 1;
  else
    CommonInventory[it->first] = 1;
}

int		main()
{
  zappy::Network net;
  zappy::Player	player(&net);
}
