//
// C_Take.cpp for Take in /home/vigner_g/rendu/PSU_2016_zappy
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Mon Jun 26 15:08:46 2017 vigner_g
// Last update Wed Jun 28 17:19:30 2017 vigner_g
//

#include <iostream> //debug
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
  if (response != "ok" || response != "ko")
    throw client_exception("Server drunk", __LINE__, __FILE__);
  else if (response == "ko")
    throw client_exception("Item is not available", __LINE__, __FILE__);
  else
    player.getOwnInventory().addItem(this->item);
  return (true);
}
