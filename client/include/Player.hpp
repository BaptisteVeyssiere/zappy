//
// Player.hpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 16:44:15 2017 vigner_g
// Last update Wed Jun 28 17:04:21 2017 vigner_g
//

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

#include <string>
#include <vector>
#include "World.h"
#include "Network.hpp"
#include "Inventory.hpp"
#include "Map.hpp"

//direction north 0 west 1 south 2 east 3

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
    Inventory				CommonInventory;
    Map					map;
    int					teamNbPlayer;
    int					nbOfEgg;
    int					slot;

  private:
    Player(Player &other);
    Player	&operator=(Player &other);

  public:
    Player(World &);
    ~Player();

  private:
    int		facingToAngle();

  public:
    void	SetTeamNbPlayer(int nb);
    void	SetId(int id);
    void	AddALvl();
    void	setFood(int nbr);

  public:
    Inventory	&getOwnInventory();
    Inventory	&getSharedInventory();
    t_position	&getFacing();
    t_position	&getPosition();
    t_position	getAbsolutePos(t_position &relative_pos);
    Map		&getMap();
    int		&getLvl();
    int		&getSlot();
  };
}

#endif // !__PLAYER_HPP__
