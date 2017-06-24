//
// C_inventory.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 18:10:48 2017 Nathan Scutari
// Last update Sat Jun 24 15:11:15 2017 Nathan Scutari
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

void		zappy::C_inventory::addArg(std::string arg)
{
  throw client_exception("Inventory does not take any argument",
			 __LINE__, __FILE__);
}

bool		zappy::C_inventory::getResponse(Player &player, std::string &response)
{
  int		food;

  food = std::stoi(response); //inventory sert à voir combien de vie il reste,
			      //le reste est déjà stocké
  //player life = food
  return (true);
}
