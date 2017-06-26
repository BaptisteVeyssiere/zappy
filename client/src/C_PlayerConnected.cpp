//
// C_PlayerConnected.cpp for PlayerConnected in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 17:00:51 2017 vigner_g
// Last update Sat Jun 24 17:21:54 2017 vigner_g
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

void		zappy::C_PlayerConnected::addArg(std::string arg)
{
  throw client_exception("PlayerConnected does not take any argument",
			 __LINE__, __FILE__);
}

bool		zappy::C_PlayerConnected::IsNbr(std::string arg)
{
  for(int i = 0; i < (strlen(str) - 1); i++)
    {
      if((int)str[i] > 9)
	return (false);
    }
  return (true);
}

bool		zappy::C_PlayerConnected::getResponse(Player &player, std::string &response)
{
  if (IsNbr(response) == false)
    throw client_exception("Server drunk", __LINE__, __FILE__);
  else
    player.SetTeamNbPlayer(std::stoi(reponse));
  return (true);
}
