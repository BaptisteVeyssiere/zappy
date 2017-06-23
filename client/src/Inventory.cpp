//
// Inventory.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 18:10:48 2017 Nathan Scutari
// Last update Fri Jun 23 18:44:10 2017 Nathan Scutari
//

#include "Inventory.hpp"
#include "Exception.hpp"

zappy::Inventory::Inventory()
  :ICommand(), command("Inventory")
{

}

zappy::Inventory::~Inventory()
{

}

std::string	&zappy::Inventory::getStr()
{
  return (command);
}

void		zappy::Inventory::addArg(std::string arg)
{
  throw client_exception("Inventory does not take any argument",
			 __LINE__, __FILE__);
}

std::string	zappy::Inventory::getArg(int nbr)
{
  throw client_exception("Inventory does not have any arg",
			 __LINE__, __FILE__);
}

bool		zappy::Inventory::getResponse(Player &player, std::string &response)
{
  int		food;

  food = std::stoi(response); //inventory sert à voir combien de vie il reste,
			      //le reste est déjà stocké
  //player life = food
  return (true);
}
