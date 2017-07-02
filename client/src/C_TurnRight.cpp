//
// C_TurnRight.cpp for Forward in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jun 24 15:25:31 2017 vigner_g
// Last update Fri Jun 30 16:47:33 2017 Nathan Scutari
//

#include "C_TurnRight.hpp"
#include "Exception.hpp"

zappy::C_TurnRight::C_TurnRight()
  :ICommand(), command("Right")
{

}

zappy::C_TurnRight::~C_TurnRight()
{

}

std::string	&zappy::C_TurnRight::getStr()
{
  return (command);
}

void		zappy::C_TurnRight::addArg(UNUSED std::string arg)
{
  throw client_exception("TurnRight does not take any argument",
			 __LINE__, __FILE__);
}

bool		zappy::C_TurnRight::getResponse(Player &player, std::string &response)
{
  static t_position pos[4] =
    {
      {0, -1},
      {1, 0},
      {0, 1},
      {-1, 0},
    };
  if (response != "ok")
    throw client_exception("Server drunk", __LINE__, __FILE__);
  for (int i = 0 ; i < 4 ; ++i)
    if (pos[i].x == player.getFacing().x &&
	pos[i].y == player.getFacing().y)
      {
	player.getFacing().x = pos[(i + 1 == 4) ? 0 : i + 1].x;
	player.getFacing().y = pos[(i + 1 == 4) ? 0 : i + 1].y;
	return (true);
      }
  throw client_exception("I'm drunk", __LINE__, __FILE__);
  return (true);
}