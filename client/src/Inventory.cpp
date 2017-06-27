//
// Inventory.cpp for Inventory in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Thu Jun 22 22:02:54 2017 vigner_g
// Last update Tue Jun 27 16:19:24 2017 Nathan Scutari
//

#include "Network.hpp"
#include "Inventory.hpp"

zappy::Inventory::Inventory()
{
}

zappy::Inventory::~Inventory()
{
}

void	zappy::Inventory::addItem(std::string item)
{
  auto it = this->inv.find(item);
  if (it != this->inv.end())
    this->inv[it->first] += 1;
  else
    this->inv[it->first] = 1;
}

void	zappy::Inventory::reset()
{
  this->inv.clear();
}

void	zappy::Inventory::reset(Inventory &other)
{
  this->inv.clear();
  this->inv = other.inv;
}

void	zappy::Inventory::addToInventory(Inventory &other)
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

void		zappy::Inventory::broadcast()
{
}

int		zappy::Inventory::delItem(std::string item)
{
  auto it = this->inv.find(item);
  if (it != this->inv.end())
    this->inv[it->first] -= 1;
  else
    return (-1);
}
