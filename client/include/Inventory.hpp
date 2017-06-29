//
// Inventory.hpp for Inventory in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 15:19:58 2017 vigner_g
// Last update Thu Jun 29 14:17:17 2017 Nathan Scutari
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
    void	refreshLook();
    int		getLook();
    void	reset();
    void	reset(Inventory &other);
    void	broadcast();
    void	addToInventory(Inventory &other);
    void	addItem(std::string item);
    bool	isEmpty();
    int		delItem(std::string item);
    Inventory	operator+(Inventory &other);
  };
}

#endif // !__INVENTORY_HPP_
