//
// C_TurnRight.cpp for Forward in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 15:25:31 2017 vigner_g
// Last update Tue Jun 27 15:15:30 2017 vigner_g
//

#include "C_TurnRight.hpp"
#include "Exception.hpp"

zappy::C_TurnRight::C_TurnRight()
  :ICommand(), command("Right")
{

}

zappy::C_TurnRight::~C_TurnRight()
{

}

std::string	&zappy::C_TurnRight::getStr()
{
  return (command);
}

void		zappy::C_TurnRight::addArg(std::string arg)
{
  throw client_exception("TurnRight does not take any argument",
			 __LINE__, __FILE__);
}

bool		zappy::C_TurnRight::getResponse(Player &player, std::string &response)
{
  if (response != "ok") //peut renvoyer que ok pour cette commande
    throw client_exception("Server drunk", __LINE__, __FILE__);
  player.getPosition().x =
    (player.getPosition().x > 1) ? -1 : (player.getPosition().x + 1);
  player.getPosition().y =
    (player.getPosition().y > 1) ? -1 : (player.getPosition().y + 1);
  return (true);
}
