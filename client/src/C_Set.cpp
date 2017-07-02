//
// C_Set.cpp for Take in /home/vigner_g/rendu/PSU_2016_zappy
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Mon Jun 26 15:08:46 2017 vigner_g
// Last update Sat Jul  1 21:18:05 2017 Nathan Scutari
//

#include <iostream> //debug
#include "C_Set.hpp"
#include "Exception.hpp"

zappy::C_Set::C_Set()
  :ICommand(), command("Set"), item()
{
}

zappy::C_Set::~C_Set()
{
}

std::string	&zappy::C_Set::getStr()
{
  return (command);
}

void	zappy::C_Set::addArg(std::string arg)
{
  command += " " + arg;
  item = arg;
}

bool	zappy::C_Set::getResponse(Player &player, std::string &response)
{
  if (response != "ok" && response != "ko")
    throw client_exception("Server drunk", __LINE__, __FILE__);
  if ((player.getOwnInventory().delItem(this->item)) == -1)
    throw client_exception("AI drunk, item is not in the inventory", __LINE__, __FILE__);
  if (response == "ok")
    player.getMap().access(player.getPosition().y ,player.getPosition().x).addItem(this->item);
  return (true);
}