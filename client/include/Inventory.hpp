//
<<<<<<< HEAD
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
=======
// Inventory.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 18:33:01 2017 Nathan Scutari
// Last update Fri Jun 23 18:43:12 2017 Nathan Scutari
//

#ifndef __INVENTORY_HPP__
# define __INVENTORY_HPP__

#include <string>
#include "ICommand.hpp"

namespace zappy
{
  class Inventory : public ICommand
  {
  private:
    std::string	command;
>>>>>>> 3185bc16d4dcd0e4ef6bac61f8afc0a610413337

  private:
    Inventory(Inventory &other);
    Inventory	&operator=(Inventory &other);

  public:
    Inventory();
    ~Inventory();
<<<<<<< HEAD
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
=======

  public:
    std::string	&getStr();
    void	addArg(std::string);
    std::string	getArg(int);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__INVENTORY_HPP__
>>>>>>> 3185bc16d4dcd0e4ef6bac61f8afc0a610413337
