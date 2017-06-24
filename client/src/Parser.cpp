//
// Parser.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Sat Jun 24 16:38:47 2017 Nathan Scutari
// Last update Sat Jun 24 17:24:04 2017 Nathan Scutari
//

#include <unistd.h>
#include <getopt.h>
#include <iostream>
#include "Parser.hpp"
#include "Client.hpp"
#include "Exception.hpp"

zappy::Parser::Parser()
  :machine(), port(), team()
{
  machine = "localhost";
}

zappy::Parser::~Parser()
{

}

void	zappy::Parser::parseArgs(int ac, char **av)
{
  char	arg;

  while ((arg = getopt(ac, av, "p:n:h:")) != -1)
    {
      if (arg == 'p')
	port = optarg;
      else if (arg == 'n')
	team = optarg;
      else if (arg == 'h')
	machine = optarg;
      else
	throw client_exception("Invalid argument", __LINE__, __FILE__);
    }
  if (port.empty() || team.empty())
    {
      zappy::Client::usage();
      throw client_exception("Missing argument", __LINE__, __FILE__);
    }
}

std::string	&zappy::Parser::getMachine()
{
  return (machine);
}

std::string	&zappy::Parser::getTeam()
{
  return (team);
}

std::string	&zappy::Parser::getPort()
{
  return (port);
}
