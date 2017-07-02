//
// C_Set.hpp for C_set in /home/vigner_g/rendu/PSU_2016_zappy
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Mon Jun 26 15:01:57 2017 vigner_g
// Last update Sat Jul  1 16:06:19 2017 Nathan Scutari
//

#ifndef __SET_HPP__
# define __SET_HPP__

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

#endif // !__SET_HPP__
