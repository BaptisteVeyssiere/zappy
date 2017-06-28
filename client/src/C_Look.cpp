//
// C_Look.cpp for Forward in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 15:25:31 2017 vigner_g
// Last update Wed Jun 28 15:58:12 2017 vigner_g
//

#include "C_Look.hpp"
#include "Exception.hpp"
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

void		zappy::C_Look::addArg(std::string arg)
{
  throw client_exception("Look does not take any argument",
			 __LINE__, __FILE__);
}

std::string	getSubString(std::string &phrase, std::string delimiter)
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
  int		j;
  int		size;
  int		k;

  j = 1;
  size = 1;
  response.erase(0, 1);
  response.erase(response.size() - 1 , response.size());
  while ((sub = getSubString(response, ",")) != "*end*" && response.size() > 0 && j < player.getLvl())
    {
      k = (-size / 2);
      while (k <= (size / 2))
	{
	  while ((sub2 = getSubString(sub, " ")) != "*end*" && sub2.size() > 0)
	    {
	      player.getMap().access
		(player.getPosition().x + (j * player.getFacing().y) + (player.getFacing().x * k),
		 player.getPosition().y + (j * player.getFacing().x) + (player.getFacing().y * k))
		.addItem(sub2);
	    }
	  k += 1;
	}
      j += 1;
      size += 2;
    }
  return (true);
}
