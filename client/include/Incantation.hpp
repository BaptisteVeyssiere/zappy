//
// Incantation.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 18:07:33 2017 Nathan Scutari
// Last update Fri Jun 23 18:20:44 2017 Nathan Scutari
//

#ifndef __INCANTATION_HPP__
# define __INCANTATION_HPP__

#include <string>
#include "ICommand.hpp"
#include "Player.hpp"

namespace zappy
{
  class Incantation : public ICommand
  {
  private:
    std::string	command;

  private:
    Incantation(Incantation &other);
    Incantation	&operator=(Incantation &other);

  public:
    Incantation();
    ~Incantation();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    std::string	getArg(int);
    bool	getResponse(Player &, std::string &);
  };
}

#endif // !__INCANTATION_HPP__
