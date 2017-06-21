//
// CommandBuffer.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/src
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 20 18:14:03 2017 Nathan Scutari
// Last update Wed Jun 21 18:34:41 2017 Nathan Scutari
//

#include "CommandBuffer.hpp"
#include "Exception.hpp"

zappy::CommandBuffer::CommandBuffer()
{
  buffer.clear();
}

zappy::CommandBuffer::~CommandBuffer()
{

}

std::string	zappy::CommandBuffer::getAndRemoveCmd()
{
  std::string	cmd;
  size_t	pos;

  if ((pos = buffer.find("\n")) == std::string::npos)
    throw client_exception("Unexpected buffer data (use Network::isCmdReady ?)",
			   __LINE__, __FILE__);
  cmd = buffer.substr(0, pos + 1);
  buffer.erase(0, pos + 1);
  return (cmd);
}

void	zappy::CommandBuffer::addInBuff(const std::string &msg)
{
  buffer += msg;
  while (buffer.front() == '\n')
    buffer.erase(0, 1);
}

bool	zappy::CommandBuffer::isCmdInBuff() const
{
  if (buffer.find("\n") == std::string::npos || buffer.size() < 2)
    return (false);
  return (true);
}
