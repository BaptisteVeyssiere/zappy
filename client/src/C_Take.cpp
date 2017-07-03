//
// C_Take.cpp for Take in /home/vigner_g/rendu/PSU_2016_zappy
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Mon Jun 26 15:08:46 2017 vigner_g
// Last update Sun Jul  2 23:36:05 2017 Nathan Scutari
//

#include <iostream>
#include "C_Take.hpp"
#include "Exception.hpp"

zappy::C_Take::C_Take()
  :ICommand(), command("Take"), item()
{
}

zappy::C_Take::~C_Take()
{
}

std::string	&zappy::C_Take::getStr()
{
  return (command);
}

void	zappy::C_Take::addArg(std::string arg)
{
  command += " " + arg;
  item = arg;
}

bool	zappy::C_Take::getResponse(Player &player, std::string &response)
{
  if (response != "ok" && response != "ko")
    throw client_exception("Server drunk", __LINE__, __FILE__);
  else if (response == "ok")
    {
      player.getOwnInventory().addItem(this->item);
      player.getMap().access(player.getPosition().y ,player.getPosition().x).delItem(this->item);
    }
  else
    {
      player.getMap().access(player.getPosition().y ,player.getPosition().x).zeroItem(this->item);
    }
  return (true);
}
