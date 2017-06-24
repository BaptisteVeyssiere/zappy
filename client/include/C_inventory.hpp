//
// C_inventory.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 18:33:01 2017 Nathan Scutari
// Last update Sat Jun 24 15:09:25 2017 Nathan Scutari
//

#ifndef __INVENTORY_HPP__
# define __INVENTORY_HPP__

#include <string>
#include "ICommand.hpp"

namespace zappy
{
  class C_inventory : public ICommand
  {
  private:
    std::string	command;

  private:
    C_inventory(C_inventory &other);
    C_inventory	&operator=(C_inventory &other);

  public:
    C_inventory();
    ~C_inventory();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__INVENTORY_HPP__
