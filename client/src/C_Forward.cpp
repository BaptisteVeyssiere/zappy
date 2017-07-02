//
// C_Forward.cpp for Forward in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 15:25:31 2017 vigner_g
// Last update Sun Jul  2 23:35:36 2017 Nathan Scutari
//

#include "C_Forward.hpp"
#include "Exception.hpp"

zappy::C_Forward::C_Forward()
  :ICommand(), command("Forward")
{

}

zappy::C_Forward::~C_Forward()
{

}

std::string	&zappy::C_Forward::getStr()
{
  return (command);
}

void		zappy::C_Forward::addArg(UNUSED std::string arg)
{
  throw client_exception("Forward does not take any argument",
			 __LINE__, __FILE__);
}

bool		zappy::C_Forward::getResponse(Player &player, std::string &response)
{
  if (response != "ok")
    throw client_exception("Server drunk", __LINE__, __FILE__);
  player.getPosition().x = (player.getPosition().x + player.getFacing().x);
  player.getPosition().y = (player.getPosition().y + player.getFacing().y);
  return (true);
}
