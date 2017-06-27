//
// Player.hpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 16:44:15 2017 vigner_g
// Last update Tue Jun 27 15:10:56 2017 vigner_g
//

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

#include <string>
#include <vector>
#include "World.h"
#include "Network.hpp"
#include "Inventory.hpp"

//direction north 0 west 1 south 2 east 3

namespace	zappy
{
  class Player
  {
    /*  private:
    int					id;
    int					lvl;
    t_position				pos;
    t_position		       		facing;
    int					food;
    Inventory				OwnInventory;
    Inventory				CommonInventory;
    //std::vector<std::vector<t_tile>>	GameMap;
    Map					map;
    int					teamNbPlayer;
    int					nbOfEgg;

  private:
    Player(Player &other);
    Player	&operator=(Player &other);

  public:
    Player();
    ~Player();

  public:
    void	SetTeamNbPlayer(int nb);
    void	SetId(int id);
    void	AddALvl();
    */
  public:
    Inventory	&getOwnInventory() const;
    Inventory	&getSharedInventory() const;
    t_position	&getFacing() const;
    t_position	&getPosition() const;
  };
}

#endif // !__PLAYER_HPP__
