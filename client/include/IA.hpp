//
// IA.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 27 17:58:03 2017 Nathan Scutari
// Last update Mon Jul  3 18:09:01 2017 Nathan Scutari
//

#ifndef __IA_HPP__
# define __IA_HPP__

#include "ICommand.hpp"
#include "C_Forward.hpp"
#include "Player.hpp"
#include "Exploration.hpp"
#include "Elevation.hpp"
#include "Join.hpp"

namespace zappy
{
  class IA
  {
  private:
    int		egg;
    Player	*mPlayer;
    Exploration	mExploration;
    Elevation	mElevation;
    Join	mJoin;

  private:
    IA(IA &other);
    IA	&operator=(IA &other);

  public:
    IA();
    ~IA();

  private:
    void	refreshTile();

  public:
    void	init(Player *);
    ICommand	*makeAChoice();
    Elevation	*getEleInstance();
    Join	*getJoinInstance();
  };
}

#endif // !IA_HPP__
