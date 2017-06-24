//
// C_Forward.hpp for C_Forward in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 14:37:39 2017 vigner_g
// Last update Sat Jun 24 15:46:53 2017 vigner_g
//

#ifndef __FORWARD_HPP__
# define __FORWARD_HPP__

#include <string>
#include "ICommand.hpp"
#include "Player.hpp"

namespace zappy
{
  class C_Forward : public ICommand
  {
  private:
    std::string	command;

  private:
    C_Forward(C_Forward &other);
    C_Forward	&operator=(C_Forward &other);

  public:
    C_Forward();
    ~C_Forward();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    std::string	getArg(int);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__FORWARD_HPP__
