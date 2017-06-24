//
// Fork.hpp for Fork$ in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 14:53:57 2017 vigner_g
// Last update Sat Jun 24 15:47:47 2017 vigner_g
//

#ifndef __FORK_HPP__
# define __FORK_HPP__

#include <string>
#include "ICommand.hpp"
#include "Player.hpp"

namespace zappy
{
  class C_Fork : public ICommand
  {
  private:
    std::string	command;

  private:
    C_Fork(C_Fork &other);
    C_Fork	&operator=(C_Fork &other);

  public:
    C_Fork();
    ~C_Fork();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    std::string	getArg(int);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__FORK_HPP__
