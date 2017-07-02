//
// Exploration.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/src
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Thu Jun 29 11:18:57 2017 Nathan Scutari
// Last update Sat Jul  1 21:25:33 2017 Nathan Scutari
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
    t_position	pos = {0, 0};
    int		value = 300;
    std::queue<ICommand *> path = std::queue<ICommand *>();
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
    std::list<t_position>	*getVision();
    ICommand			*needToLook(std::list<t_position> *);
    bool			objectOnSelf() const;
    ICommand			*takeObject();
    void			createPath();
    std::list<tileValue>	*fillValues(std::list<t_position> *);
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
    static std::list<t_position>	*getVision(Player&);
    void			init(Player *);
    ICommand			*explore();
    void			moveToPos(tileValue &);
  };
}

#endif // !__EXPLORATION_HPP__
