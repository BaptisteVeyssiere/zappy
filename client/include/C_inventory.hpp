//
// C_inventory.hpp for C_inventory in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 15:50:28 2017 vigner_g
// Last update Sat Jun 24 15:53:24 2017 vigner_g
//


#ifndef	__INVENTORY_HPP_
# define __INVENTORY_HPP_

#include	<map>

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

#endif // !__INVENTORY_HPP_
