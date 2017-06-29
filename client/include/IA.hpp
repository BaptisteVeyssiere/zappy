//
// IA.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 27 17:58:03 2017 Nathan Scutari
// Last update Thu Jun 29 11:32:32 2017 Nathan Scutari
//

#ifndef __IA_HPP__
# define __IA_HPP__

#include "ICommand.hpp"
#include "C_Forward.hpp"
#include "Player.hpp"
#include "Exploration.hpp"

namespace zappy
{
  class IA
  {
  private:
    Player	*mPlayer;
    Exploration	mExploration;

  private:
    IA(IA &other);
    IA	&operator=(IA &other);

  public:
    IA();
    ~IA();

  public:
    void	init(Player *);
    ICommand	*makeAChoice();
  };
}

#endif // !IA_HPP__
