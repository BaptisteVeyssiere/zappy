//
// Client.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 20 16:10:12 2017 Nathan Scutari
// Last update Fri Jun 30 17:22:01 2017 Nathan Scutari
//

#include <unistd.h>
#include <iostream>
#include "Client.hpp"
#include "Exception.hpp"

zappy::Client::Client(std::string port, std::string team, std::string machine)
  :info(), mNet(), choice(NULL)
{
  info = mNet.connectToServer(machine, port, team);
  player = std::make_unique<Player>(info);
  std::cout << "Connected to zappy server !" << std::endl;
}

zappy::Client::~Client()
{
  mNet.disconnect();
  std::cout << "Disconnected from zappy server" << std::endl;
}

void	zappy::Client::usage()
{
  std::cout << "Usage ./zappy_ai -p port -n name -h machine" << std::endl;
  std::cout << "\tport\tis the port number" << std::endl;
  std::cout << "\tname\tis the name of the team" << std::endl;
  std::cout << "\tmachine\tis the name of the machine; localhost by default"
	    << std::endl;
}

void	zappy::Client::launch()
{
  std::string	server_msg;

  ia.init(&(*player));
  std::cout << "Starting game loop" << std::endl;
  while (1)
    {
      if (mNet.isReadable())
	mNet.readMsg();
      if (mNet.isCmdReady())
	{
	  server_msg = mNet.getNextCmd();
	  if (mCmdMgr.isResponse(server_msg) && !choice)
	    throw client_exception("Unexpected server msg", __LINE__, __FILE__);
	  else if (choice)
	    {
	      std::cout << "Received: " << server_msg << std::endl;
	      if (choice->getResponse(*player, server_msg))
		choice = NULL;
	      std::cout << "\n" << std::endl;
	    }
	  else
	    mCmdMgr.analyseData(server_msg, *player);
	}
      if (!choice)
	{
	  if ((choice = ia.makeAChoice()))
	    mNet.sendMsg(choice->getStr());
	}
      usleep(100);
      }
}
