//
// TurnLeft.hpp for TurnLeft in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 14:50:40 2017 vigner_g
// Last update Sat Jun 24 15:47:16 2017 vigner_g
//

#ifndef __TURNLEFT_HPP__
# define __TURNLEFT_HPP__

#include <string>
#include "ICommand.hpp"
#include "Player.hpp"

namespace zappy
{
  class C_TurnLeft : public ICommand
  {
  private:
    std::string	command;

  private:
    C_TurnLeft(C_TurnLeft &other);
    C_TurnLeft	&operator=(C_TurnLeft &other);

  public:
    C_TurnLeft();
    ~C_TurnLeft();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    std::string	getArg(int);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__TURNLEFT_HPP__
