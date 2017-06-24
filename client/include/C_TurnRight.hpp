//
// TurnRight.hpp for TurnRight in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 14:51:32 2017 vigner_g
// Last update Sat Jun 24 15:09:21 2017 vigner_g
//

#ifndef __TURNRIGHT_HPP__
# define __TURNRIGHT_HPP__

#include <string>
#include "ICommand.hpp"
#include "Player.hpp"

namespace zappy
{
  class C_TurnRight : public ICommand
  {
  private:
    int		waiting;
    std::string	command;

  private:
    C_TurnRight(C_TurnRight &other);
    C_TurnRight	&operator=(C_TurnRight &other);

  public:
    C_TurnRight();
    ~C_TurnRight();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    std::string	getArg(int);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__TURNRIGHT_HPP__
