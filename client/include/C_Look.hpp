//
// TurnLeft.hpp for TurnLeft in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 14:50:40 2017 vigner_g
// Last update Wed Jun 28 16:31:22 2017 vigner_g
//

#ifndef __LOOK_HPP__
# define __LOOK_HPP__

#include <string>
#include "ICommand.hpp"
#include "Player.hpp"

namespace zappy
{
  class C_Look : public ICommand
  {
  private:
    std::string	command;

  private:
    C_Look(C_Look &other);
    C_Look	&operator=(C_Look &other);

  public:
    C_Look();
    ~C_Look();

  public:
    std::string	&getStr();
    void	addArg(std::string);
    std::string	getArg(int);
    bool	getResponse(Player &, std::string &);
    std::string	getSubString(std::string &phrase, std::string delimiter);
  };
}

#endif // !__LOOK_HPP__
