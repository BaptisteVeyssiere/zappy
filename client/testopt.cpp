//
// testopt.cpp for test in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Sat Jun 24 17:02:05 2017 Nathan Scutari
// Last update Sat Jun 24 17:04:29 2017 Nathan Scutari
//

#include "Parser.hpp"

int	main(int ac, char **av)
{
  zappy::Parser	parser;

  parser.parseArgs(ac, av);
  return (0);
}
