//
// main.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/src
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 20 15:38:47 2017 Nathan Scutari
// Last update Tue Jun 20 16:09:55 2017 Nathan Scutari
//

#include "Client.hpp"

int	main(int ac, char **av)
{
  zappy::Client	*client;

  if (ac != 3 && ac != 4)
    return (zappy::Client::usage());
  else if (ac == 3)
    client = new zappy::Client(av[1], av[2]);
  else
    client = new zappy::Client(av[1], av[2], av[3]);
  try
    {
      client->launch();
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
