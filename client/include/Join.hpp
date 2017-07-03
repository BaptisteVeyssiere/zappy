//
// Join.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Sun Jul  2 16:52:01 2017 Nathan Scutari
// Last update Mon Jul  3 18:09:12 2017 Nathan Scutari
//

#ifndef __JOIN_HPP__
# define __JOIN_HPP__

#include "ICommand.hpp"
#include "Player.hpp"

namespace zappy
{
  class Join
  {
  private:
    Player	*mPlayer;
    bool	waiting;

  private:
    Join(Join &other);
    Join	&operator=(Join &other);

  public:
    Join();
    ~Join();

  private:
    ICommand	*getOrientation();
    ICommand	*followBroadcast();

  public:
    void	init(Player *);
    ICommand	*join();
    void	setWaiting(bool);
    Join	*getInstance();
  };
}

#endif // !__JOIN_HPP__
