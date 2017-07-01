//
// Elevation.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/src
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 30 23:55:55 2017 Nathan Scutari
// Last update Sat Jul  1 01:55:57 2017 Nathan Scutari
//

#include "C_inventory.hpp"
#include "Elevation.hpp"

zappy::Elevation::Elevation()
  :requirements(false), elevating(false), mPlayer(NULL)
{

}

zappy::Elevation::~Elevation()
{

}

void	zappy::Elevation::init(Player *player)
{
  mPlayer = player;
}

bool	zappy::Elevation::hasEnough(std::string item, int nbr)
{
  Inventory	inv;

  inv = mPlayer->getOwnInventory();
  if (inv.getInv()[item] >= nbr)
    return (true);
  return (false);
}

bool	zappy::Elevation::tryUp()
{
  static std::string	items[] =
    {
      "food", "linemate", "deraumere", "sibur", "mendiane",
      "phiras", "thystame", "player"
    };
  static int		required[][8] =
    {
      {0},
      {20, 1, 0, 0, 0, 0, 0, 1},
      {25, 1, 1, 1, 0, 0, 0, 2},
      {25, 2, 0, 1, 0, 2, 0, 2},
      {25, 1, 1, 2, 0, 1, 0, 4},
      {25, 1, 2, 1, 3, 0, 0, 4},
      {25, 1, 2, 3, 0, 1, 0, 6},
      {25, 2, 2, 2, 2, 2, 1, 6}
    };
  Inventory	inv;

  inv = mPlayer->getOwnInventory();
  for (int i = 0 ; i < 9 ; ++i)
    if (!hasEnough(items[i], required[mPlayer->getLvl()][i]))
      return (false);
  requirements = true;
  return (true);
}

zappy::ICommand	*zappy::Elevation::elevate()
{

}

zappy::ICommand	*zappy::Elevation::check()
{
  ICommand	*choice = NULL;
  static int	turn = 0;

  if (requirements)
    return (elevate());
  if (++turn == 10)
    {
      turn = 0;
      return (new C_inventory);
    }
  else if (turn == 0 && (tryUp()))
    return (elevate());
  return (NULL);
}
