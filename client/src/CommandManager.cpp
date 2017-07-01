//
// CommandManager.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Jun 26 10:11:32 2017 Nathan Scutari
// Last update Sat Jul  1 23:40:08 2017 vigner_g
//

#include <iostream>
#include <functional>
#include <cctype>
#include "CommandManager.hpp"
#include "Player.hpp"

std::string     retNext(std::string str, std::string tofind)
{
  size_t        pos;

  if ((pos = str.find(tofind)) != std::string::npos)
    str.erase(0, pos);
  if ((pos = str.find(" ")) != std::string::npos)
    str.erase(0, pos + 1);
  if ((pos = str.find(" ")) != std::string::npos)
    str.erase(pos, str.back());
  return(str);
}

void	elevation(std::string &msg, zappy::Player &player)
{
  std::string	tmp;
  int		tlvl;
  int		idToJoin;
  std::string	tmpToBroadcast;

  tmp = retNext(msg , "Elevation");
  if (!(isdigit(tmp[0])) || (idToJoin = std::stoi(tmp)) == 0)
    return;
  tmp = retNext(msg , "LVL");
  if (!(isdigit(tmp[0])) || (tlvl = std::stoi(tmp)) == 0)
    return;
  if (player.getLvl() == tlvl)
    {
      tmpToBroadcast = "Free ";
      tmpToBroadcast += std::to_string(idToJoin);
      tmpToBroadcast += " PlayerID ";
      tmpToBroadcast += std::to_string(player.getID());
    }
  std::cout << "elevation: " << msg << std::endl;
}

void	playerIsFree(std::string &msg, zappy::Player &player)
{
  std::string	tmp;
  int		elevatingID;
  int		distantID;

  tmp = retNext(msg , "Free");
  if (!(isdigit(tmp[0])) || (elevatingID = std::stoi(tmp)) == 0)
    return;
  if (player.getRegroup().isElevating() == true && elevatingID == player.getID())
    {
      tmp = retNext(msg , "PlayerID");
      if (!(isdigit(tmp[0])) || (distantID = std::stoi(tmp)) == 0)
	return;
      player.getRegroup().addID(distantID);
    }
  std::cout << "PlayerIsFree: " << msg << std::endl;
}

void	comeMyFriend(std::string &msg, zappy::Player &player)
{
  std::string	tmp;
  int		elevatingID;
  int		distantID;
  int		direction;

  tmp = retNext(msg , "message");
  if (!(isdigit(tmp[0])) || (direction = std::stoi(tmp)) == 0)
    return;
  tmp = retNext(msg , "Come");
  if (!(isdigit(tmp[0])) || (elevatingID = std::stoi(tmp)) == 0)
    return;
  tmp = retNext(msg , "PlayerID");
  if (!(isdigit(tmp[0])) || (distantID = std::stoi(tmp)) == 0)
    return;
  if (distantID == player.getID())
    {
      player.getRegroup().setJoining(elevatingID);
      player.getRegroup().setDirection(direction);
    }
  std::cout << "comeMyFriend: " << msg << std::endl;
}

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

void	zappy::CommandManager::analyseData(std::string &msg, Player &player)
{
  std::map<std::string, std::function<void(std::string &, Player &)>>        fptr;

  fptr["Elevation"] = elevation;
  fptr["Free"] = playerIsFree;
  fptr["Come"] = comeMyFriend;
  for (auto it = fptr.begin(); it != fptr.end(); it ++)
    {
      auto fi = msg.find(it->first);
      if (fi != std::string::npos)
  	return (it->second(msg, player));
    }
}
