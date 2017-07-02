//
// CommandManager.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Jun 26 10:11:32 2017 Nathan Scutari
// Last update Sun Jul  2 00:57:58 2017 Nathan Scutari
//

#include <iostream>
#include <functional>
#include "CommandManager.hpp"
#include "Player.hpp"
#include "ICommand.hpp"
#include "C_incantation.hpp"

void	getMyId(std::string &msg, zappy::Player &player)
{
  std::cout << "getMyId: " << msg << std::endl;
}
void	elevation(std::string &msg, zappy::Player &player)
{
  std::cout << "elevation: " << msg << std::endl;
}
void	broadcastInventory(std::string &msg, zappy::Player &player)
{
  std::cout << "broadcastInventory: " << msg << std::endl;
}
void	playerConnecting(std::string &msg, zappy::Player &player)
{
  std::cout << "PlayerIsFree: " << msg << std::endl;
}
void	playerIsFree(std::string &msg, zappy::Player &player)
{
  std::cout << "PlayerIsFree: " << msg << std::endl;
}
void	comeMyFriend(std::string &msg, zappy::Player &player)
{
  std::cout << "comeMyFriend: " << msg << std::endl;
}

zappy::CommandManager::CommandManager()
  :refs({"message", "eject", "dead", "Elevation underway"})
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

bool	zappy::CommandManager::isResponse(std::string &msg, ICommand **stock,
					  bool ele)
{
  size_t	pos;

  cleanString(msg);
  for (unsigned int i = 0 ; i < refs.size() ; ++i)
    {
      if ((pos = msg.find(refs[i])) == 0)
	{
	  if (refs[i] == "Elevation underway" && ele == false)
	    {
	      *stock = new C_incantation(true);
	      return (false);
	    }
	  else if (refs[i] == "Elevation underway" && ele == true)
	    return (true);
	  std::cout << "Received data: " << refs[i] << std::endl;
	  return (false);
	}
    }
  return (true);
}

void	zappy::CommandManager::analyseData(std::string &msg, Player &player)
{
  if (msg == "Elevation underway")
    return ;
  std::map<std::string, std::function<void(std::string &, Player &)>>        fptr;

  fptr["YourId"] = getMyId;
  fptr["Elevation"] = elevation;
  fptr["Inventory"] = broadcastInventory;
  fptr["Hello"] = playerConnecting;
  fptr["Free"] = playerIsFree;
  fptr["Come"] = comeMyFriend;
  for (auto it = fptr.begin(); it != fptr.end(); it ++)
    {
      auto fi = msg.find(it->first);
      if (fi != std::string::npos)
  	it->second(msg, player);
    }

}