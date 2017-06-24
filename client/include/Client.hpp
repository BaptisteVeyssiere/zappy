//
// Client.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Jun 19 22:50:21 2017 Nathan Scutari
// Last update Sat Jun 24 16:14:20 2017 Nathan Scutari
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
    ICommand	*choice;
    //AI

  private:
    Client();
    Client(Client &other);
    Client	&operator=(Client &other);

  public:
    Client(std::string port, std::string team, std::string machine = "localhost");
    ~Client();

    void	launch();
    static void	usage();
  };
}

#endif // !__CLIENT_HPP__
