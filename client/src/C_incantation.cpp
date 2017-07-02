//
// C_incantation.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 18:10:48 2017 Nathan Scutari
// Last update Sun Jul  2 16:48:50 2017 vigner_g
//

#include "C_incantation.hpp"
#include "Exception.hpp"

zappy::C_incantation::C_incantation(bool state)
  :ICommand(), waiting(state), command("Incantation")
{
}

zappy::C_incantation::~C_incantation()
{

}

std::string	&zappy::C_incantation::getStr()
{
  return (command);
}

void		zappy::C_incantation::addArg(UNUSED std::string arg)
{
  throw client_exception("Incantation does not take any argument",
			 __LINE__, __FILE__);
}

bool		zappy::C_incantation::getResponse(Player &player,
						  std::string &response)
{
  if (waiting == false)
    {
      player.setLeveling(false);
      waiting = true;
      return (false);
    }
  if (response.find("Current level") != std::string::npos)
    {
      player.AddALvl();
    }
  player.getRegroup().stopElevating();
  return (true);
}
