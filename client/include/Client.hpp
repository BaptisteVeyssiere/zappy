//
// Client.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Jun 19 22:50:21 2017 Nathan Scutari
// Last update Tue Jun 20 16:36:58 2017 vigner_g
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
    Client	&opeartor(Client &other);

  public:
    Client(int port, char *team, std::string machine = "localhost");
    ~Client();

    void	launch();
  };
}

#endif // !__CLIENT_HPP__
