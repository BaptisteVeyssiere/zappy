//
// Player.hpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 16:44:15 2017 vigner_g
// Last update Wed Jun 21 19:12:29 2017 vigner_g
//

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

#include <string>
#include <vector>
#include <map>
#include "World.h"
#include "Network.hpp"

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
    std::map<std::string, int>		inventory;
    std::map<std::string, int>		CommonInventory;
    std::vector<std::vector<t_tile>>	GameMap;
    int					teamNbPlayer;

  private:
    Player();
    Player(Player &other);
    Player	&opeartor(Player &other);
    void	BroadcastOwnInventory();
    void	ResetCommonInventory();
    void	AddToCommonInventory(std::map<std::string, int> other);
    void	TurnLeft();
    void	TurnRight();
    void	GoForward();
    void	PickupItem();
    void	SetItem();
    void	Fork();
    void	Eject();

  public:
    Player(Network *network);
    ~Player();
  };
}

#endif // !__CLIENT_HPP__
