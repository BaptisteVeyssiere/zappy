//
// Player.hpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 16:44:15 2017 vigner_g
// Last update Fri Jun 30 19:01:09 2017 vigner_g
//

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

#include <string>
#include <vector>
#include "World.h"
#include "Network.hpp"
#include "Inventory.hpp"
#include "Map.hpp"

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
    std::map<int, Inventory>		commonInventory;
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

  public:
    void	SetTeamNbPlayer(int nb);
    void	SetId(int id);
    void	AddALvl();
    void	setFood(int nbr);
    int		facingToAngle();

  public:
    Inventory	&getOwnInventory();
    std::map<int, Inventory>	&getCommonInventory();
    void	addToCommonInventory(int lvl, std::string item, int nbr);
    void	resetCommonInventory();
    t_position	&getFacing();
    t_position	&getPosition();
    t_position	getAbsolutePos(t_position &relative_pos);
    Map		&getMap();
    int		&getLvl();
    int		&getSlot();
    int		&getFood();
  };
}

#endif // !__PLAYER_HPP__
