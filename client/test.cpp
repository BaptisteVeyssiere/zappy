//
// test.cpp for test in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 20 18:05:47 2017 Nathan Scutari
// Last update Wed Jun 21 17:51:29 2017 Nathan Scutari
//

#include <iostream>
#include <unistd.h>
#include "Network.hpp"

int	main(int ac, char **av)
{
  zappy::Network	net;
  std::string		msg("Ayyy");

  net.connectToServer("localhost", av[1], "TeamJPP");
  net.sendMsg(msg);
  while (1)
    {
      if (net.isReadable())
	{
	  net.readMsg();
	  while (net.isCmdReady())
	    std::cout << net.getNextCmd() << std::endl;
	}
      usleep(100);
    }
  return (0);
}
