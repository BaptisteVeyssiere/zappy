//
// Inventory.hpp for Inventory in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Thu Jun 22 21:58:26 2017 vigner_g
// Last update Fri Jun 23 16:07:43 2017 vigner_g
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

  private:
    Inventory(Inventory &other);
    Inventory	&operator=(Inventory &other);

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
