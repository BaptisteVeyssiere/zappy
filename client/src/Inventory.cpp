//
// Inventory.cpp for Inventory in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Thu Jun 22 22:02:54 2017 vigner_g
// Last update Fri Jun 30 23:04:57 2017 vigner_g
//

#include "Network.hpp"
#include "Inventory.hpp"
#include <iostream>

zappy::Inventory::Inventory() : look_time(-1), inv()
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
    this->inv[item] = 1;
}

void	zappy::Inventory::addItem(std::string item, int nbr)
{
  auto it = this->inv.find(item);
  if (it != this->inv.end())
    this->inv[it->first] += nbr;
  else
    this->inv[item] = nbr;
}

void	zappy::Inventory::reset()
{
  this->inv.clear();
}

void	zappy::Inventory::reset(Inventory &other)
{
  this->inv.clear();
}

void	zappy::Inventory::addToInventory(Inventory &other)
{
  for (auto it = other.inv.begin(); it != other.inv.end(); it++)
    this->inv[it->first] += it->second;
}

zappy::Inventory	zappy::Inventory::operator+(Inventory &other)
{
  for (auto it = other.inv.begin(); it != other.inv.end(); it++)
    this->inv[it->first] += it->second;
  return (*this);
}

void		zappy::Inventory::broadcast()
{
  for (auto it = inv.begin(); it != inv.end(); ++it)
    std::cout << it->first << " => " << it->second << std::endl;
}

void	zappy::Inventory::refreshLook()
{
  look_time = 0;
}

int		zappy::Inventory::getLook()
{
  return (look_time);
}

int		zappy::Inventory::delItem(std::string item)
{
  auto it = this->inv.find(item);
  if (it != this->inv.end())
    this->inv[it->first] -= 1;
  else
    return (-1);
  return (0);
}

int		zappy::Inventory::zeroItem(std::string item)
{
  auto it = this->inv.find(item);
  if (it != this->inv.end())
    this->inv[it->first] = 0;
  else
    return (-1);
  return (0);
}

std::map<std::string, int>	&zappy::Inventory::getInv()
{
  return (this->inv);
}

bool	zappy::Inventory::isEmpty()
{
  return (inv.empty());
}

// std::map<std::string, int>	&zappy::Inventory::getInv()
// {
//   return (inv);
// }

void	zappy::Inventory::addLook()
{
  if (look_time >= 0)
    ++look_time;
}
