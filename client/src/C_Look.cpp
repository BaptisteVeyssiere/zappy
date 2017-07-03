//
// C_Look.cpp for Forward in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 15:25:31 2017 vigner_g
// Last update Sat Jul  1 23:54:41 2017 vigner_g
//

#include <iostream>
#include "C_Look.hpp"
#include "Exception.hpp"
#include "Exploration.hpp"
#include <string>

zappy::C_Look::C_Look()
  :ICommand(), command("Look")
{

}

zappy::C_Look::~C_Look()
{

}

std::string	&zappy::C_Look::getStr()
{
  return (command);
}

void		zappy::C_Look::addArg(UNUSED std::string arg)
{
  throw client_exception("Look does not take any argument",
			 __LINE__, __FILE__);
}

std::string	zappy::C_Look::getSubString(std::string &phrase, std::string delimiter)
{
  std::string	ret;
  size_t	pos;

  if ((pos = phrase.find(delimiter)) == std::string::npos)
    {
      ret = phrase.substr(0, std::string::npos);
      phrase.erase(0, std::string::npos);
      return (ret);
    }
  ret = phrase.substr(0, pos);
  phrase.erase(0, pos + delimiter.length());
  return (ret);
}

bool		zappy::C_Look::getResponse(Player &player, std::string &response)
{
  std::string	sub;
  std::string	sub2;
  std::list<t_position> *p;

  response.erase(0, 1);
  response.erase(response.size() - 1 , response.size());
  std::cout << "Look response" << std::endl;
  p = Exploration::getVision(player);
  std::list<t_position>::iterator it = p->begin();
  while ((sub = getSubString(response, ",")) != "*end*" && response.size() > 0)
    {
      player.getMap().access(it->y, it->x).reset();
      player.getMap().access(it->y, it->x).refreshLook();
      while ((sub2 = getSubString(sub, " ")) != "*end*" && sub.size() > 0)
	{
	  if (sub2 != " " && !(sub2.empty()))
	    {
	      player.getMap().access(it->y, it->x).addItem(sub2);
	    }
	}
      if (sub2 != "player" && sub2 != " " && !(sub2.empty()))
	{
	  player.getMap().access(it->y, it->x).addItem(sub2);
	}
      it++;
    }
  player.getMap().access(it->y, it->x).reset();
  while ((sub2 = getSubString(sub, " ")) != "*end*" && sub.size() > 0)
    {
      if (sub2 != "player" && sub2 != " " && !(sub2.empty()))
	{
	  player.getMap().access(it->y, it->x).addItem(sub2);
	}
    }
  if (sub2 != "player" && sub2 != " " && !(sub2.empty()))
    {
      player.getMap().access(it->y, it->x).addItem(sub2);
    }
  return (true);
}
