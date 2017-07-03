//
// CommandManager.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Jun 26 10:11:32 2017 Nathan Scutari
// Last update Mon Jul  3 20:37:48 2017 Nathan Scutari
//

#include <iostream>
#include <functional>
#include <cctype>
#include "CommandManager.hpp"
#include "Player.hpp"
#include "ICommand.hpp"
#include "C_incantation.hpp"

zappy::CommandManager::CommandManager()
  :refs({"message", "eject", "dead", "Elevation underway"})
{

}

zappy::CommandManager::~CommandManager()
{

}

std::string     zappy::CommandManager::retNext(std::string str, std::string tofind)
{
  size_t        pos;

  if ((pos = str.find(tofind)) != std::string::npos)
    str.erase(0, pos);
  else
    return ("none");
  if ((pos = str.find(" ")) != std::string::npos)
    str.erase(0, pos + 1);
  if ((pos = str.find(" ")) != std::string::npos)
    str.erase(pos, str.back());
  return(str);
}

void	zappy::CommandManager::elevation(std::string &msg, zappy::Player &player)
{
  zappy::AskId	ask;
  std::string	tmp;
  int		tlvl;
  int		idToJoin;
  std::string	tmpToBroadcast;

  std::cout << "elevation: " << msg << std::endl;
  tmp = retNext(msg , "Elevation");
  std::cout << "tmp:" << tmp << std::endl;
  if (!(isdigit(tmp[0])) || (idToJoin = std::stoi(tmp)) == 0)
    return;
  tmp = retNext(msg , "LVL");
  std::cout << "tmp:" << tmp << std::endl;
  if (!(isdigit(tmp[0])) || (tlvl = std::stoi(tmp)) == 0)
    return;
  ask.id = idToJoin;
  ask.lvl = tlvl;
  ask.timeout = 0;
  player.addAsk(ask);
  if (player.getLvl() == tlvl &&
      player.getFood() >= 25 && player.getRegroup().getJoining() == -1)
    {
      tmpToBroadcast = "Free ";
      tmpToBroadcast += std::to_string(idToJoin);
      tmpToBroadcast += " PlayerID ";
      tmpToBroadcast += std::to_string(player.getID());
      player.setToBroadcast(tmpToBroadcast);
    }
}

void	zappy::CommandManager::playerIsFree(std::string &msg, zappy::Player &player)
{
  std::string	tmp;
  int		elevatingID;
  int		distantID;

  std::cout << "PlayerIsFree: " << msg << std::endl;
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
}

void	zappy::CommandManager::come(std::string &msg, zappy::Player &player)
{
  std::string	tmp;
  int		elevatingID;
  int		distantID;
  int		direction;
  int		i;

  std::cout << "comeMyFriend: " << msg << std::endl;
  i = 1;
  tmp = retNext(msg , "message");
  if (!(isdigit(tmp[0])))
    return;
  direction = std::stoi(tmp);
  tmp = retNext(msg , "Come");
  if (!(isdigit(tmp[0])) || (elevatingID = std::stoi(tmp)) == 0)
    return;
  while ((tmp = retNext(msg , "PlayerID" + std::to_string(i))) != "none")
    {
      if (!(isdigit(tmp[0])) || (distantID = std::stoi(tmp)) == 0)
	return;
      if (distantID == player.getID())
	{
	  player.getRegroup().setElevTimeout(10);
	  player.getRegroup().setJoining(elevatingID);
	  player.getRegroup().setDirection(direction);
	}
      i += 1;
    }
}

void	zappy::CommandManager::cancel(std::string &msg, zappy::Player &player)
{
  std::string	tmp;
  int		elevatingID;


  std::cout << "cancel: " << msg << std::endl;
  tmp = retNext(msg , "Cancel");
  if (!(isdigit(tmp[0])) || (elevatingID = std::stoi(tmp)) == 0)
    return;
  if (elevatingID == player.getRegroup().getJoining())
    {
      player.getRegroup().stopJoining();
      player.getRegroup().setJoining(-1);
      player.getJoin()->setWaiting(false);
    }
}

void	zappy::CommandManager::here(std::string &msg, zappy::Player &player)
{
  std::string	tmp;
  int		elevatingID;
  int		distantID;


  std::cout << "here: " << msg << std::endl;
  tmp = retNext(msg , "Here");
  if (!(isdigit(tmp[0])) || (elevatingID = std::stoi(tmp)) == 0)
    return;
  tmp = retNext(msg , "PlayerID");
  if (!(isdigit(tmp[0])) || (distantID = std::stoi(tmp)) == 0)
    return;
  if (elevatingID == player.getID())
    {
      for (auto it = player.getRegroup().getIDS().begin() ;
	   it != player.getRegroup().getIDS().end() ; ++it)
	if (*it == distantID)
	  {
	    it = player.getRegroup().getIDS().erase(it);
	    --it;
	    player.getMap().access(player.getPosition().y,player.getPosition().x).
	      addItem("player", 1);
	    player.getRegroup().setPlayerNbr(player.getRegroup().getPlayerNbr() - 1);
	    if (player.getRegroup().getPlayerNbr() == 0)
	      player.startElev();
	  }
    }
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

  std::cout << "analyseData " << msg << std::endl;
  fptr["Elevation"] = CommandManager::elevation;
  fptr["Free"] = CommandManager::playerIsFree;
  fptr["Come"] = CommandManager::come;
  fptr["Cancel"] = CommandManager::cancel;
  fptr["Here"] = CommandManager::here;
  for (auto it = fptr.begin(); it != fptr.end(); it ++)
    {
      auto fi = msg.find(it->first);
      if (fi != std::string::npos)
  	return (it->second(msg, player));
    }
}
