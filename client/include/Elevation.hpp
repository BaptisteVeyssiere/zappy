//
// Elevation.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/src
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 30 23:47:49 2017 Nathan Scutari
// Last update Sat Jul  1 01:51:23 2017 Nathan Scutari
//

#ifndef __ELEVATION_HPP__
# define __ELEVATION_HPP__

#include "ICommand.hpp"
#include "Player.hpp"

namespace zappy
{
  class Elevation
  {
  private:
    bool	requirements;
    bool	elevating;
    Player	*mPlayer;

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
  };
}

#endif // !__ELEVATION_HPP__
