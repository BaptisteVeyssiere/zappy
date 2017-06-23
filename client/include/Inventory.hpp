//
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

  private:
    Inventory(Inventory &other);
    Inventory	&operator=(Inventory &other);

  public:
    Inventory();
    ~Inventory();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    std::string	getArg(int);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__INVENTORY_HPP__
