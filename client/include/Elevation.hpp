//
// Elevation.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/src
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 30 23:47:49 2017 Nathan Scutari
// Last update Sun Jul  2 17:38:45 2017 Nathan Scutari
//

#ifndef __ELEVATION_HPP__
# define __ELEVATION_HPP__

#include "ICommand.hpp"
#include "Player.hpp"

#define ELEVATION_ASKING_TIMEOUT 10
#define ELEVATION_COMING_TIMEOUT 40

namespace zappy
{
  class Player;
  class ICommand;
}

namespace zappy
{
  class Elevation
  {
  private:
    bool	requirements;
    bool	elevating;
    Player	*mPlayer;
    int		required[8][8] =
      {
	{0, 0, 0, 0, 0, 0, 0, 0},
	{12, 1, 0, 0, 0, 0, 0, 1},
	{25, 1, 1, 1, 0, 0, 0, 2},
	{25, 2, 0, 1, 0, 2, 0, 2},
	{25, 1, 1, 2, 0, 1, 0, 4},
	{25, 1, 2, 1, 3, 0, 0, 4},
	{25, 1, 2, 3, 0, 1, 0, 6},
	{25, 2, 2, 2, 2, 2, 1, 6}
      };
    std::string	items[8] =
    {
      "food", "linemate", "deraumere", "sibur", "mendiane",
      "phiras", "thystame", "player"
    };

  private:
    Elevation(Elevation &other);
    Elevation	&operator=(Elevation &other);

  public:
    Elevation();
    ~Elevation();

  private:
    bool	hasEnough(std::string, int);
    bool	tryUp();

  public:
    void	init(Player *);
    ICommand	*check();
    ICommand	*elevate();
    Elevation	*getInstance();
    int		getStoneValue(const std::string &) const;
  };
}

#endif // !__ELEVATION_HPP__
