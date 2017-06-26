//
// C_Take.hpp for C_take in /home/vigner_g/rendu/PSU_2016_zappy
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Mon Jun 26 14:09:18 2017 vigner_g
// Last update Mon Jun 26 14:11:57 2017 vigner_g
//

#ifndef __TAKE_HPP__
# define __TAKE_HPP__

#include <string>
#include "ICommand.hpp"

namespace zappy
{
  class	C_Take : public ICommand
  {
  private:
    std::string	command;
    std::string	item;

  private:
    C_Take(C_Take &other);
    C_Take	&operator=(C_Take &other);

  public:
    C_Take();
    ~C_Take();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__TAKE_HPP__
