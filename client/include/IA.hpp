//
// IA.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 27 17:58:03 2017 Nathan Scutari
// Last update Tue Jun 27 18:54:21 2017 Nathan Scutari
//

#ifndef __IA_HPP__
# define __IA_HPP__

#include "ICommand.hpp"
#include "C_Forward.hpp"
#include "Player.hpp"

namespace zappy
{
  class IA
  {
  private:
    IA(IA &other);
    IA	&operator=(IA &other);

  public:
    IA();
    ~IA();

  public:
    ICommand	*makeAChoice(Player &);
  };
}

#endif // !IA_HPP__
