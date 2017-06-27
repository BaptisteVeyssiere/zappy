//
// C_Look.cpp for Forward in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 15:25:31 2017 vigner_g
// Last update Mon Jun 26 16:47:04 2017 vigner_g
//

#include "C_Look.hpp"
#include "Exception.hpp"

zappy::C_Look::C_Look()
  :ICommand(), command("Look")
{

}

zappy::C_Look::~C_Look()
{

}

std::string	&zappy::C_Look::getStr()
{
  return (command);
}

void		zappy::C_Look::addArg(std::string arg)
{
  throw client_exception("Look does not take any argument",
			 __LINE__, __FILE__);
}

bool		zappy::C_Look::getResponse(Player &player, std::string &response)
{

  //remplir la map perso du client
}
