//
// C_inventory.hpp for C_inventory in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 15:50:28 2017 vigner_g
// Last update Tue Jun 27 16:12:07 2017 Nathan Scutari
//


#ifndef	__C_INVENTORY_HPP_
# define __C_INVENTORY_HPP_

#include <string>
#include "ICommand.hpp"

namespace	zappy
{
  class C_inventory : public ICommand
  {
  private:
    std::string	command;

  private:
    C_inventory(C_inventory &other);
    C_inventory &operator=(C_inventory &other);

  public:
    C_inventory();
    ~C_inventory();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__C_INVENTORY_HPP_
