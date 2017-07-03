//
// Player.hpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 16:44:15 2017 vigner_g
// Last update Mon Jul  3 18:14:13 2017 Nathan Scutari
//

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

#include <list>
#include <string>
#include <vector>
#include "World.h"
#include "Network.hpp"
#include "Inventory.hpp"
#include "Map.hpp"
#include "Elevation.hpp"
#include "Regroup.hpp"
#include "ICommand.hpp"
#include "Join.hpp"

namespace zappy
{
  class ICommand;
  class Join;
}

namespace	zappy
{
  struct	AskId
  {
    int		id = 0;
    int		lvl = 0;
    int		timeout = 0;
  };

  class Player
  {
  private:
    int					id;
    int					lvl;
    t_position				pos;
    t_position		       		facing;
    int					food;
    Inventory				OwnInventory;
    Map					map;
    int					teamNbPlayer;
    int					nbOfEgg;
    int					slot;
    std::string				onGoingAction;
    std::string				toBroadcast;
    Regroup				regroup;
    bool				leveling;
    Elevation				*mElevation;
    Join				*mJoin;
    bool				start_elev;
    std::list<AskId>			askList;

  private:
    Player(Player &other);
    Player	&operator=(Player &other);

  public:
    Player(World &);
    ~Player();

  public:
    void	SetTeamNbPlayer(int nb);
    void	setLeveling(bool);
    void	SetId(int id);
    void	AddALvl();
    void	setFood(int nbr);
    void	clearToBroadcast();
    void	setToBroadcast(std::string msg);
    int		facingToAngle();

  public:
    void	init(Elevation *, Join *);
    Inventory	&getOwnInventory();
    t_position	&getFacing();
    t_position	&getPosition();
    t_position	getAbsolutePos(t_position &relative_pos);
    Map		&getMap();
    int		&getID();
    int		&getLvl();
    int		&getSlot();
    int		&getFood();
    Regroup	&getRegroup();
    bool	&getLeveling();
    int		getStoneValue(const std::string &) const;
    std::string	&getToBroadcast();
    void	startElev();
    void	stopElev();
    bool	isElev();
    void	addAsk(AskId &);
    void	refreshAskList();
    bool	lowestId();
    Join	*getJoin();

  public:
    ICommand	*elevation();
    ICommand	*cancel();
    ICommand	*here();
    ICommand	*come();
  };
}

#endif // !__PLAYER_HPP__
