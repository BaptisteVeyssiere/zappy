//
// Join.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Sun Jul  2 16:52:01 2017 Nathan Scutari
// Last update Sun Jul  2 16:56:31 2017 Nathan Scutari
//

#ifndef __JOIN_HPP__
# define __JOIN_HPP__

#include "Icommand.hpp"
#include "Player.hpp"

namespace zappy
{
  class Join
  {
  private:
    Join(Join &other);
    Join	&operator=(Join &other);

  public:
    Join();
    ~Join();

  public:
    void	init(Player *);
    ICommand	*join();
  };
}

#endif // !__JOIN_HPP__
