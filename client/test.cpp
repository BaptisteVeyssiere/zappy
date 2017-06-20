//
// test.cpp for test in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 20 18:05:47 2017 Nathan Scutari
// Last update Tue Jun 20 18:53:20 2017 Nathan Scutari
//

#include "Network.hpp"

int	main(int ac, char **av)
{
  zappy::Network	net;

  net.connectToServer("10.10.253.53", av[1], "TeamJPP");
  return (0);
}
