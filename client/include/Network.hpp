//
// Network.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Jun 19 21:11:43 2017 Nathan Scutari
// Last update Tue Jun 20 18:51:12 2017 Nathan Scutari
//

#ifndef __NETWORK_HPP__
# define __NETWORK_HPP__

#include <string>
#include "CommandBuffer.hpp"
#include "World.h"

namespace	zappy
{
  class	Network
  {
  private:
    CommandBuffer	cmdBuffer;
    int			server_fd = -1;

  private:
    Network(Network &other);
    Network	&operator=(Network &other);

  public:
    Network();
    ~Network();

  public:
    World		connectToServer(const std::string &host,
					const std::string &port,
					const std::string &team);
    bool		isReadable() const;
    void		readMsg() const;
    bool		isCmdReady() const;
    std::string		getNextCmd() const;
    void		sendMsg(std::string &msg) const;
    void		disconnect();
  };
}

#endif // !__NETWORK_HPP__
