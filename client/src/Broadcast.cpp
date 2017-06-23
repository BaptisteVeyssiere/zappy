//
// Broadcast.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 17:08:43 2017 Nathan Scutari
// Last update Fri Jun 23 18:02:30 2017 Nathan Scutari
//

#include <iostream> //debug
#include "Broadcast.hpp"
#include "Exception.hpp"

zappy::Broadcast::Broadcast()
  :ICommand(), command("Broadcast")
{
}

zappy::Broadcast::~Broadcast()
{
}

std::string	&zappy::Broadcast::getStr()
{
  return (command);
}

void	zappy::Broadcast::addArg(std::string arg)
{
  command += " " + arg;
}

std::string	zappy::Broadcast::getArg(int nbr)
{
  size_t	pos_s;
  size_t	pos_e;

  pos_e = -1;
  for (int i = 0 ; i < nbr + 1 ; ++i)
    {
      pos_s = pos_e;
      if ((pos_e = command.find(" ", pos_s + 1))
	  == std::string::npos)
	{
	  if (i == nbr)
	    pos_e = command.size();
	  else
	    throw client_exception("Arg " + std::to_string(nbr) +
				   " does not exist",
				   __LINE__, __FILE__);
	}
    }
  return (command.substr(pos_s + 1, pos_e - pos_s - 1));
}

void	zappy::Broadcast::getResponse(Player &player, std::string &response)
{
  if (response != "ok") //peut renvoyer que ok pour cette commande
    throw client_exception("Server drunk", __LINE__, __FILE__);
  return ;
}
