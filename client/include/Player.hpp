//
<<<<<<< HEAD
// Player.hpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 16:44:15 2017 vigner_g
// Last update Fri Jun 23 16:18:54 2017 vigner_g
=======
// Player.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 17:39:34 2017 Nathan Scutari
// Last update Fri Jun 23 18:45:40 2017 Nathan Scutari
>>>>>>> 3185bc16d4dcd0e4ef6bac61f8afc0a610413337
//

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

<<<<<<< HEAD
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
=======
namespace zappy
{
  class Player
  {

>>>>>>> 3185bc16d4dcd0e4ef6bac61f8afc0a610413337
  };
}

#endif // !__PLAYER_HPP__
