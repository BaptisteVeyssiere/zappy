//
// Client.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Jun 19 22:50:21 2017 Nathan Scutari
// Last update Tue Jun 20 15:41:34 2017 Nathan Scutari
//

#ifndef __CLIENT_HPP__
# define __CLIENT_HPP__

#include "Network.hpp"
#include "World.h"

namespace zappy
{
  class Client
  {
  private:
    World	info;
    Network	mNet;
    //AI

  private:
    Client();
    Client(Client &other);
    Client	&operator=(Client &other);

  public:
    Client(int port, char *team, std::string machine = "localhost");
    ~Client();

    void	launch();
    static void	usage();
  };
}

#endif // !__CLIENT_HPP__
