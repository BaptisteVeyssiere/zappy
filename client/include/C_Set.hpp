//
// C_Set.hpp for C_set in /home/vigner_g/rendu/PSU_2016_zappy
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Mon Jun 26 15:01:57 2017 vigner_g
// Last update Mon Jun 26 15:17:05 2017 vigner_g
//

#ifndef __TAKE_HPP__
# define __TAKE_HPP__

#include <string>
#include "ICommand.hpp"

namespace zappy
{
  class	C_Set : public ICommand
  {
  private:
    std::string	command;
    std::string	item;

  private:
    C_Set(C_Set &other);
    C_Set	&operator=(C_Set &other);

  public:
    C_Set();
    ~C_Set();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__TAKE_HPP__
