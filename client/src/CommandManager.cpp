//
// CommandManager.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Jun 26 10:11:32 2017 Nathan Scutari
// Last update Wed Jun 28 16:46:34 2017 vigner_g
//

#include <iostream>
#include "CommandManager.hpp"

zappy::CommandManager::CommandManager()
  :refs({"message", "eject", "dead"})
{

}

zappy::CommandManager::~CommandManager()
{

}

void	zappy::CommandManager::cleanString(std::string &msg) const
{
  while (msg.front() == ' ')
    msg.erase(0, 1);
}

bool	zappy::CommandManager::isResponse(std::string &msg)
{
  size_t	pos;

  cleanString(msg);
  for (unsigned int i = 0 ; i < refs.size() ; ++i)
    {
      if ((pos = msg.find(refs[i])) == 0)
	{
	  std::cout << "Received data: " << refs[i] << std::endl;
	  return (false);
	}
    }
  return (true);
}

void	zappy::CommandManager::analyseData( std::string &msg, Player &player)
{
  //mlkjhgfd
}
