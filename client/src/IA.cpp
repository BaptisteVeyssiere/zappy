//
// IA.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 27 18:50:41 2017 Nathan Scutari
// Last update Tue Jun 27 18:55:20 2017 Nathan Scutari
//

#include "IA.hpp"

zappy::IA::IA()
{

}

zappy::IA::~IA()
{

}

zappy::ICommand	*zappy::IA::makeAChoice(Player &player)
{
  return (new C_Forward);
}