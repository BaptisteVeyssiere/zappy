//
// Player.hpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 16:44:15 2017 vigner_g
// Last update Sat Jul  1 22:46:50 2017 vigner_g
//

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

#include <string>
#include <vector>
#include "World.h"
#include "Network.hpp"
#include "Inventory.hpp"
#include "Map.hpp"
#include "Regroup.hpp"

namespace	zappy
{
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

  private:
    Player(Player &other);
    Player	&operator=(Player &other);

  public:
    Player(World &);
    ~Player();

  public:
    void	SetTeamNbPlayer(int nb);
    void	SetId(int id);
    void	AddALvl();
    void	setFood(int nbr);
    void	clearToBroadcast();
    void	setToBroadcast(std::string msg);
    int		facingToAngle();

  public:
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
  };
}

#endif // !__PLAYER_HPP__
