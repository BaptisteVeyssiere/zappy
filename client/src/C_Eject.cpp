//
// C_Eject.cpp for C_Eject in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 16:58:22 2017 vigner_g
// Last update Wed Jun 28 16:34:28 2017 vigner_g
//

#include "C_Eject.hpp"
#include "Exception.hpp"

zappy::C_Eject::C_Eject()
  :ICommand(), command("Eject")
{

}

zappy::C_Eject::~C_Eject()
{

}

std::string	&zappy::C_Eject::getStr()
{
  return (command);
}

void		zappy::C_Eject::addArg(UNUSED std::string arg)
{
  throw client_exception("Eject does not take any argument",
			 __LINE__, __FILE__);
}

bool		zappy::C_Eject::getResponse(UNUSED Player &player, std::string &response)
{
  if (response != "ok" && response != "ko")
    throw client_exception("Server drunk", __LINE__, __FILE__);
  return (true);
}
