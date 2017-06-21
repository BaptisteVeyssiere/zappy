//
// Player.cpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 17:04:08 2017 vigner_g
// Last update Wed Jun 21 19:39:38 2017 vigner_g
//

#include "Player.hpp"

zappy::Player::Player(Network *network) : pos.x(0), pos.y(0)
{
  // network->sendMsg("");
}

zappy::Player::~Player()
{
}

zappy::Player::ResetCommonInventory()
{
  this->CommonInventory.clear();
  this->CommonInventory = inventory;
}

zappy::Player::AddToCommonInventory(std::map<std::string, int> other)
{
  for(auto it = other.begin(); it != other.end(); it++)
    this->CommonInventory[it->first] += it->second;
  other.clear();
}

zappy::Player::TurnLeft()
{
  this->direction -= 1;
  direction = (direction < 0) ? 3 : direction;
  //envoyer la commande correspondante au serveur
}

zappy::Player::TurnRight()
{
  this->direction += 1;
  direction = (direction > 3) ? 0 : direction;
  //envoyer la commande correspondante au serveur
}

zappy::player::GoForward()
{
  switch (this->direction)
    {
    case 0: this->position.x += 1;
      break;
    case 1: this->position.y += 1;
      break;
    case 3: this->position.x -= 1;
      break;
    case 4: this->position.y -= 1;
      break;
    }
}

int		main()
{
  zappy::Network net;
  zappy::Player	player(&net);
}
