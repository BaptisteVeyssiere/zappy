//
// Player.hpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 16:44:15 2017 vigner_g
// Last update Fri Jun 23 16:18:54 2017 vigner_g
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
  private:
    int					id;
    int					lvl;
    t_position				pos;
    int					food;
    int					direction;
    Inventory				OwnInventory;
    Inventory				CommonInventory;
    std::vector<std::vector<t_tile>>	GameMap;
    int					teamNbPlayer;
    int					nbOfEgg;

  private:
    Player();
    Player(Player &other);
    Player	&opeartor(Player &other);
    void	TurnLeft();
    void	TurnRight();
    void	GoForward();
    void	Fork();
    void	Eject();
    Player(Network *network);

  public:

    Player(Network *network);
    ~Player();
  };
}

#endif // !__PLAYER_HPP__
