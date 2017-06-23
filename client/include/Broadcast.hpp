//
// Broadcast.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 17:04:46 2017 Nathan Scutari
// Last update Fri Jun 23 18:20:36 2017 Nathan Scutari
//

#ifndef __BROADCAST_HPP__
# define __BROADCAST_HPP__

#include <string>
#include "ICommand.hpp"

namespace zappy
{
  class	Broadcast : public ICommand
  {
  private:
    std::string	command;

  private:
    Broadcast(Broadcast &other);
    Broadcast	&operator=(Broadcast &other);

  public:
    Broadcast();
    ~Broadcast();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    std::string	getArg(int);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__BROADCAST_HPP__
