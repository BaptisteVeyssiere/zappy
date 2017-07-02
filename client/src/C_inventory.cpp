//
// C_inventory.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 18:10:48 2017 Nathan Scutari
// Last update Fri Jun 30 19:11:38 2017 Nathan Scutari
//

#include "C_inventory.hpp"
#include "Exception.hpp"

zappy::C_inventory::C_inventory()
  :ICommand(), command("Inventory")
{

}

zappy::C_inventory::~C_inventory()
{

}

std::string	&zappy::C_inventory::getStr()
{
  return (command);
}

void		zappy::C_inventory::addArg(UNUSED std::string arg)
{
  throw client_exception("Inventory does not take any argument",
			 __LINE__, __FILE__);
}

bool		zappy::C_inventory::getResponse(Player &player, std::string &response)
{
  int		food;

  if (response == "ko")
    throw client_exception("Server drunk", __LINE__, __FILE__);
  while (!isdigit(response.front()))
    {
      if (response.empty())
	throw client_exception("Server drunk", __LINE__, __FILE__);
      response.erase(0, 1);
    }
  food = std::stoi(response);
  player.setFood(food);
  return (true);
}