//
// C_PlayerConected.hpp for PleyerConnected in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 16:56:07 2017 vigner_g
// Last update Sat Jun 24 17:08:31 2017 vigner_g
//

#ifndef __PLAYERCONNECTED_HPP__
# define __PLAYERCONNECTED_HPP__

#include <string>
#include "ICommand.hpp"
#include "Player.hpp"

namespace zappy
{
  class C_PlayerConnected : public ICommand
  {
  private:
    std::string	command;

  private:
    C_PlayerConnected(C_PlayerConnected &other);
    C_PlayerConnected	&operator=(C_PlayerConnected &other);

  public:
    C_PlayerConnected();
    ~C_PlayerConnected();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    std::string	getArg(int);
    bool	getResponse(Player &, std::string &);
    bool	IsNbr(std::string arg);
  };
}

#endif // !__PLAYERCONNECTED_HPP__
