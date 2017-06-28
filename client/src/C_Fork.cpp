//
// C_Fork.cpp for Forward in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 15:25:31 2017 vigner_g
// Last update Wed Jun 28 16:34:02 2017 vigner_g
//

#include "C_Fork.hpp"
#include "Exception.hpp"

zappy::C_Fork::C_Fork()
  :ICommand(), command("Fork")
{

}

zappy::C_Fork::~C_Fork()
{

}

std::string	&zappy::C_Fork::getStr()
{
  return (command);
}

void		zappy::C_Fork::addArg(UNUSED std::string arg)
{
  throw client_exception("Fork does not take any argument",
			 __LINE__, __FILE__);
}

bool		zappy::C_Fork::getResponse(UNUSED Player &player, std::string &response)
{
  if (response != "ok")
    throw client_exception("Server drunk", __LINE__, __FILE__);
  return (true);
}
