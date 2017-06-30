//
// Inventory.hpp for Inventory in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 15:19:58 2017 vigner_g
// Last update Thu Jun 29 16:23:09 2017 vigner_g
//


#ifndef	__INVENTORY_HPP_
# define __INVENTORY_HPP_

#include	<map>

namespace	zappy
{
  class Inventory
  {
  private:
    int					look_time;
    std::map<std::string, int>		inv;

  public:
    Inventory();
    ~Inventory();
    void	reset();
    void	reset(Inventory &other);
    void	broadcast();
    void	addToInventory(Inventory &other);
    void	addItem(std::string item);
    void	addItem(std::string item, int nbr);
    int		delItem(std::string item);
    std::map<std::string, int>	&getInv();
    Inventory	operator+(Inventory &other);
  };
}

#endif // !__INVENTORY_HPP_
