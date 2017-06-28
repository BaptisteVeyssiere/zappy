//
// C_broadcast.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 17:08:43 2017 Nathan Scutari
// Last update Wed Jun 28 16:32:59 2017 vigner_g
//

#include <iostream> //debug
#include "C_broadcast.hpp"
#include "Exception.hpp"

zappy::C_broadcast::C_broadcast()
  :ICommand(), command("Broadcast")
{
}

zappy::C_broadcast::~C_broadcast()
{
}

std::string	&zappy::C_broadcast::getStr()
{
  return (command);
}

void	zappy::C_broadcast::addArg(UNUSED std::string arg)
{
  command += " " + arg;
}

bool	zappy::C_broadcast::getResponse(UNUSED Player &player, std::string &response)
{
  if (response != "ok")
    throw client_exception("Server drunk", __LINE__, __FILE__);
  return (true);
}
