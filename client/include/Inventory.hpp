//
// Inventory.hpp for Inventory in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 15:19:58 2017 vigner_g
// Last update Sat Jun 24 15:20:49 2017 vigner_g
//


#ifndef	__INVENTORY_HPP_
# define __INVENTORY_HPP_

#include	<map>

namespace	zappy
{
  class Inventory
  {
  private:
    std::map<std::string, int>		inv;

  public:
    Inventory();
    ~Inventory();
    void	Reset();
    void	Reset(Inventory &other);
    void	Broadcast(Network &net);
    void	AddToInventory(Inventory &other);
    void	PickupItem(std::string item);
    int		SetItem(std::string item);
    Inventory	operator+(Inventory &other);
  };
}

#endif // !__INVENTORY_HPP_
