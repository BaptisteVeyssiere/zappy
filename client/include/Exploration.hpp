//
// Exploration.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/src
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Jun 29 11:18:57 2017 Nathan Scutari
// Last update Thu Jun 29 17:18:59 2017 Nathan Scutari
//

#ifndef __EXPLORATION_HPP__
# define __EXPLORATION_HPP__

#include <list>
#include <queue>
#include "ICommand.hpp"
#include "Player.hpp"
#include "World.h"

#define LOOK_OLD 30
#define ABS(x) ((x < 0) ? -x : x)

namespace zappy
{

  struct	tileValue
  {
    t_position	pos;
    int		value;
    std::queue<ICommand *> path;
  };

  class Exploration
  {
  private:
    std::queue<ICommand *>	path;
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
    void			createPath();
    std::list<tileValue>	*fillValues(std::list<t_position> *);
    void			moveToPos(tileValue &);
    void			moveToDest(tileValue &, t_position &,
					   t_position &, t_position &);
    void			getOrientation(tileValue &, t_position &,
					       t_position &, int);
    int				getRightOrientation(tileValue &,
						    t_position &,
						    t_position &);
    void			fillOrientations(t_position &, t_position &,
						 bool *);
    int				foodValue();
    std::list<t_position>	*getNearbyPos();

  public:
    void			init(Player *);
    ICommand			*explore();
  };
}

#endif // !__EXPLORATION_HPP__
