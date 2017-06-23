//
<<<<<<< HEAD
// Inventory.cpp for Inventory in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Thu Jun 22 22:02:54 2017 vigner_g
// Last update Fri Jun 23 16:21:47 2017 vigner_g
//

#include "Network.hpp"
#include "Inventory.hpp"

zappy::Inventory::Inventory()
{
}

zappy::Inventory::~Inventory()
{
}

void	zappy::Inventory::PickupItem(std::string item)
{
  auto it = this->inv.find(item);
  if (it != this->inv.end())
    this->inv[it->first] += 1;
  else
    this->inv[it->first] = 1;
}

void	zappy::Inventory::Reset()
{
  this->inv.clear();
}

void	zappy::Inventory::Reset(Inventory &other)
{
  this->inv.clear();
  this->inv = other.inv;
}

void	zappy::Inventory::AddToInventory(Inventory &other)
{
  for(auto it = other.inv.begin(); it != other.inv.end(); it++)
    this->inv[it->first] += it->second;
}

zappy::Inventory	zappy::Inventory::operator+(Inventory &other)
{
  for(auto it = other.inv.begin(); it != other.inv.end(); it++)
    this->inv[it->first] += it->second;
  return (*this);
}

void		zappy::Inventory::Broadcast(Network &net)
{
}

int		zappy::Inventory::SetItem(std::string item)
{
  auto it = this->inv.find(item);
  if (it != this->inv.end())
    this->inv[it->first] -= 1;
  else
    return (-1);
=======
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
>>>>>>> 3185bc16d4dcd0e4ef6bac61f8afc0a610413337
}
