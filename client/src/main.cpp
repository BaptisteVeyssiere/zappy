//
// main.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/src
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 20 15:38:47 2017 Nathan Scutari
// Last update Sat Jun 24 17:34:52 2017 Nathan Scutari
//

#include <iostream>
#include "Client.hpp"
#include "Parser.hpp"

int	main(int ac, char **av)
{
  zappy::Parser	parser;
  zappy::Client	*client;

  try
    {
      parser.parseArgs(ac, av);
      client = new zappy::Client(parser.getPort(), parser.getTeam(),
				 parser.getMachine());
      client->launch();
    }
  catch (const std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
  return (0);
}
