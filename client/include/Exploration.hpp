//
// Exploration.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/src
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Jun 29 11:18:57 2017 Nathan Scutari
// Last update Thu Jun 29 14:18:41 2017 Nathan Scutari
//

#ifndef __EXPLORATION_HPP__
# define __EXPLORATION_HPP__

#include <list>
#include <queue>
#include "ICommand.hpp"
#include "Player.hpp"
#include "World.h"

#define LOOK_OLD 30

namespace zappy
{
  class Exploration
  {
  private:
    std::queue<t_position>	*path;
    Player			*mPlayer;

  private:
    Exploration(Exploration &other);
    Exploration	&operator=(Exploration &other);

  public:
    Exploration();
    ~Exploration();

  private:
    ICommand			*needToLook(std::list<t_position> *);
    std::list<t_position>	*getVision();
    bool			objectOnSelf() const;
    ICommand			*takeObject();

  public:
    void			init(Player *);
    ICommand			*explore();
  };
}

#endif // !__EXPLORATION_HPP__