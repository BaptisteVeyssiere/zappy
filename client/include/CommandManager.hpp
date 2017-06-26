//
// CommandManager.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Jun 26 10:05:18 2017 Nathan Scutari
// Last update Mon Jun 26 10:16:33 2017 Nathan Scutari
//

#ifndef __COMMANDMANAGER_HPP__
# define __COMMANDMANAGER_HPP__

#include <string>
#include "Player.hpp"

namespace zappy
{
  class CommandManager
  {
  private:
    std::vector<std::string>	refs;

  private:
    CommandManager(CommandManager &other);
    CommandManager	&operator=(CommandManager &other);

  public:
    CommandManager();
    ~CommandManager();

  public:
    bool	isResponse(std::string &msg);
    void	analyseData(std::string &, Player &);
  };
}

#endif // !__COMMANDMANAGER_HPP__
