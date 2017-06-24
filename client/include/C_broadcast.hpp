//
// Broadcast.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 17:04:46 2017 Nathan Scutari
// Last update Sat Jun 24 15:08:24 2017 Nathan Scutari
//

#ifndef __BROADCAST_HPP__
# define __BROADCAST_HPP__

#include <string>
#include "ICommand.hpp"

namespace zappy
{
  class	C_broadcast : public ICommand
  {
  private:
    std::string	command;

  private:
    C_broadcast(C_broadcast &other);
    C_broadcast	&operator=(C_broadcast &other);

  public:
    C_broadcast();
    ~C_broadcast();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__BROADCAST_HPP__
