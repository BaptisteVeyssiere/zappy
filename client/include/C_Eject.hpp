//
// Eject.hpp for Eject in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 14:55:21 2017 vigner_g
// Last update Sat Jun 24 15:47:03 2017 vigner_g
//

#ifndef __EJECT_HPP__
# define __EJECT_HPP__

#include <string>
#include "ICommand.hpp"
#include "Player.hpp"

namespace zappy
{
  class C_Eject : public ICommand
  {
  private:
    std::string	command;

  private:
    C_Eject(C_Eject &other);
    C_Eject	&operator=(Eject &other);

  public:
    C_Eject();
    ~C_Eject();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    std::string	getArg(int);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__EJECT_HPP__
