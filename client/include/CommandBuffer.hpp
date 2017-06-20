//
// CommandBuffer.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Jun 19 21:52:15 2017 Nathan Scutari
// Last update Wed Jun 21 00:09:12 2017 Nathan Scutari
//

#ifndef __COMMANDBUFFER_HPP__
# define __COMMANDBUFFER_HPP__

#include <string>

namespace zappy
{
  class	CommandBuffer
  {
  private:
    std::string	buffer;

  private:
    CommandBuffer(CommandBuffer &other);
    CommandBuffer	&operator=(CommandBuffer &other);

  public:
    CommandBuffer();
    ~CommandBuffer();

    bool	isCmdInBuff() const;
    std::string	getAndRemoveCmd();
    void	addInBuff(const std::string &msg);
  };
}

#endif // !COMMANDBUFFER_HPP__
