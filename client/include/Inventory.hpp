//
// Inventory.hpp for Inventory in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 15:19:58 2017 vigner_g
// Last update Fri Jun 30 23:07:23 2017 vigner_g
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
    void	addLook();
    int		getLook();
    void	reset();
    void	reset(Inventory &other);
    void	broadcast();
    void	addToInventory(Inventory &other);
    void	addItem(std::string item);
    void	addItem(std::string item, int nbr);
    bool	isEmpty();
    int		delItem(std::string item);
    int		zeroItem(std::string item);
    std::map<std::string, int>	&getInv();
    Inventory	operator+(Inventory &other);
    // std::map<std::string, int>	&getInv();
  };
}

#endif // !__INVENTORY_HPP_
