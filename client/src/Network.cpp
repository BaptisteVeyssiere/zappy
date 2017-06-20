//
// Network.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 20 16:10:35 2017 Nathan Scutari
// Last update Tue Jun 20 19:22:24 2017 Nathan Scutari
//

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "Network.hpp"

zappy::Network::Network()
{

}

zappy::Network::~Network()
{

}


bool	zappy::Network::isReadable() const
{
  int			ret;
  fd_set		set;
  static struct timeval	timerange = {0, 0};

  FD_ZERO(&set);
  FD_SET(server_fd, &set);
  if (server_fd == -1)
    throw std::exception();
  if ((ret = select(FD_SETSIZE, &set, NULL, NULL, &timerange)) == -1)
    throw std::exception();
  return ((ret == 0) ? false : true);
}

bool	zappy::Network::isCmdReady() const
{
  //commandbuffer
}

std::string	zappy::Network::getNextCmd() const
{
  //commandbuffer
}

void	zappy::Network::sendMsg(std::string &msg) const
{
  if (send(server_fd, msg.c_str(), msg.size(), 0) == -1)
    throw std::exception();
}

zappy::World	zappy::Network::connectToServer(const std::string &host,
						const std::string &port,
						const std::string &team)
{
  World			data;
  struct addrinfo	*res;
  struct protoent	*pe;

  if (getaddrinfo(host.c_str(), port.c_str(), NULL, &res) ||
      (pe = getprotobyname("TCP")) == 0 ||
      (server_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    throw std::exception();
  if (connect(server_fd, static_cast<struct sockaddr *>(res->ai_addr),
	      sizeof(*(res->ai_addr))) == -1)
    throw std::exception();
  return (data);
}
