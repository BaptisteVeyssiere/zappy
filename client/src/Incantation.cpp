//
// Incantation.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 18:10:48 2017 Nathan Scutari
// Last update Fri Jun 23 18:20:25 2017 Nathan Scutari
//

#include "Incantation.hpp"
#include "Exception.hpp"

zappy::Incantation::Incantation()
  :ICommand(), command("Incantation")
{

}

zappy::Broadcast::~Broadcast()
{

}

std::string	&zappy::Broadcast::getStr()
{
  return (command);
}

void		zappy::Broadcast::addArg(std::string arg)
{
  throw client_exception("Incantation does not take any argument",
			 __LINE__, __FILE__);
}

void		zappy::Broadcast::getArg(int nbr)
{
  throw client_exception("Incantaion does not have any arg",
			 __LINE__, __FILE__);
}

bool		zappy::Broadcast::getResponse(Player &player, std::string &response)
{
  if (waiting == 0)
    {
      waiting = 1;
      return (false);
    }
  if (response.find("Current level") != std::string::npos)
    {
      //player ++lvl
    }
  return (true);
}
