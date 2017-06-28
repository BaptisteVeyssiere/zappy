//
// C_PlayerConnected.cpp for PlayerConnected in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 17:00:51 2017 vigner_g
// Last update Wed Jun 28 16:33:28 2017 vigner_g
//

#include <string>
#include "C_PlayerConnected.hpp"
#include "Exception.hpp"

zappy::C_PlayerConnected::C_PlayerConnected()
  :ICommand(), command("Connect_nbr")
{

}

zappy::C_PlayerConnected::~C_PlayerConnected()
{

}

std::string	&zappy::C_PlayerConnected::getStr()
{
  return (command);
}

void		zappy::C_PlayerConnected::addArg(UNUSED std::string arg)
{
  throw client_exception("PlayerConnected does not take any argument",
			 __LINE__, __FILE__);
}

bool		zappy::C_PlayerConnected::IsNbr(std::string arg)
{
  for(int i = 0; i < (arg.size() - 1); i++)
    {
      if(static_cast<int>(arg[i]) > 9)
	return (false);
    }
  return (true);
}

bool		zappy::C_PlayerConnected::getResponse(Player &player, std::string &response)
{
  if (IsNbr(response) == false)
    throw client_exception("Server drunk", __LINE__, __FILE__);
  else
    player.getSlot() = std::stoi(response);
  return (true);
}
