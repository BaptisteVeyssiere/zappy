//
// test.cpp for test in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 20 18:05:47 2017 Nathan Scutari
// Last update Sat Jun 24 15:12:13 2017 Nathan Scutari
//

#include <iostream>
#include <unistd.h>
#include "C_broadcast.hpp"
#include "Network.hpp"

int	main(int ac, char **av)
{
  zappy::Network	net;
  std::string		msg("Ayyy");
  zappy::ICommand		*comm;


  comm = new zappy::C_broadcast();
  comm->addArg("arg1 arg2 arg3");
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
