//
// Forward.hpp for Forward in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 14:37:39 2017 vigner_g
// Last update Sat Jun 24 14:37:40 2017 vigner_g
//

#ifndef __FORWARD_HPP__
# define __FORWARD_HPP__

#include <string>
#include "ICommand.hpp"
#include "Player.hpp"

namespace zappy
{
  class Forward : public ICommand
  {
  private:
    int		waiting;
    std::string	command;

  private:
    Forward(Forward &other);
    Forward	&operator=(Forward &other);

  public:
    Forward();
    ~Forward();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    std::string	getArg(int);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__FORWARD_HPP__
