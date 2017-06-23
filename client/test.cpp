//
// test.cpp for test in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 20 18:05:47 2017 Nathan Scutari
// Last update Fri Jun 23 17:49:52 2017 Nathan Scutari
//

#include <iostream>
#include <unistd.h>
#include "Broadcast.hpp"
#include "Network.hpp"

int	main(int ac, char **av)
{
  zappy::Network	net;
  std::string		msg("Ayyy");
  zappy::ICommand		*comm;


  comm = new zappy::Broadcast();
  comm->addArg("message test");
  std::cout << comm->getStr() << std::endl;
  /*  try
    {
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
    }
  catch (std::exception &e)
    {
      std::cerr << e.what() << std::endl;
      }*/
  return (0);
}
