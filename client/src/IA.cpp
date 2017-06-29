//
// IA.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 27 18:50:41 2017 Nathan Scutari
// Last update Thu Jun 29 11:24:41 2017 Nathan Scutari
//

#include "IA.hpp"

zappy::IA::IA()
{

}

zappy::IA::~IA()
{

}

void	zappy::IA::init(Player *player)
{
  mPlayer = player;
  mExploration.init(player);
}

zappy::ICommand	*zappy::IA::makeAChoice()
{
  ICommand	*choice;

  choice = mExploration.explore();
  return (choice);
}
