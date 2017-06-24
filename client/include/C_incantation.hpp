//
// Incantation.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 18:07:33 2017 Nathan Scutari
// Last update Sat Jun 24 15:08:58 2017 Nathan Scutari
//

#ifndef __INCANTATION_HPP__
# define __INCANTATION_HPP__

#include <string>
#include "ICommand.hpp"
#include "Player.hpp"

namespace zappy
{
  class C_incantation : public ICommand
  {
  private:
    int		waiting;
    std::string	command;

  private:
    C_incantation(C_incantation &other);
    C_incantation	&operator=(C_incantation &other);

  public:
    C_incantation();
    ~C_incantation();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__INCANTATION_HPP__
