//
// Network.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 20 16:10:35 2017 Nathan Scutari
// Last update Mon Jun 26 12:00:58 2017 Nathan Scutari
//

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <netdb.h>
#include <unistd.h>
#include "Network.hpp"
#include "Exception.hpp"

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
  FD_SET(mSignalMgr.getSignalFd(), &set);
  if (server_fd == -1)
    throw client_exception("Connection to server lost", __LINE__, __FILE__);
  if ((ret = select(FD_SETSIZE, &set, NULL, NULL, &timerange)) == -1)
    throw client_exception("Select failed", __LINE__, __FILE__);
  else if (ret > 0 && FD_ISSET(mSignalMgr.getSignalFd(), &set))
    mSignalMgr.checkSignal();
  else if (ret > 0 && FD_ISSET(server_fd, &set))
    return (true);
  return (false);
}

bool	zappy::Network::isCmdReady() const
{
  return (cmdBuffer.isCmdInBuff());
}

std::string	zappy::Network::getNextCmd()
{
  return (cmdBuffer.getAndRemoveCmd());
}

void	zappy::Network::sendMsg(std::string &msg) const
{
  ssize_t	sent;
  ssize_t	ret;
  int		size;

  if (server_fd == -1)
    throw client_exception("Connection to server lost", __LINE__, __FILE__);
  sent = 0;
  size = msg.size();
  while (sent != size)
    {
      if ((ret = send(server_fd, msg.c_str(), msg.size(), 0)) == -1)
	throw client_exception("Failed to send message to server",
			       __LINE__, __FILE__);
      sent += ret;
      msg.erase(0, ret);
    }
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
    throw client_exception("Failed to create socket", __LINE__, __FILE__);
  while (res)
    {
      if (connect(server_fd, static_cast<struct sockaddr *>(res->ai_addr),
		  sizeof(*(res->ai_addr))) != -1)
	return (data);
      res = res->ai_next;
    }
  throw client_exception("Could not connect to " + host +
			 " on port " + port, __LINE__, __FILE__);
  return (data);
}

void	zappy::Network::readMsg()
{
  ssize_t	ret;
  static char	buffer[BUFFER_LENGTH];

  bzero(buffer, BUFFER_LENGTH);
  if ((ret = recv(server_fd, buffer, BUFFER_LENGTH, 0)) == -1)
    throw client_exception("Failed to receive message from server",
			   __LINE__, __FILE__);
  else if (ret == 0)
    disconnect();
  cmdBuffer.addInBuff(buffer);
}

void	zappy::Network::disconnect()
{
  if (server_fd != -1)
    close(server_fd);
  server_fd = -1;
}
