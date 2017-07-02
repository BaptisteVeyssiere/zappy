//
// CommandManager.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Jun 26 10:05:18 2017 Nathan Scutari
// Last update Sun Jul  2 18:03:53 2017 vigner_g
//

#ifndef __COMMANDMANAGER_HPP__
# define __COMMANDMANAGER_HPP__

#include <string>
#include "Player.hpp"
#include "ICommand.hpp"

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

  private:
    void	cleanString(std::string &) const;

  public:
    static std::string	retNext(std::string, std::string);
    static void	elevation(std::string &, Player &);
    static void	playerIsFree(std::string &, Player &);
    static void	come(std::string &, Player &);
    static void	cancel(std::string &, Player &);
    static void	free(std::string &, Player &);
    static void	here(std::string &, Player &);
    bool	isResponse(std::string &msg, ICommand **, bool);
    void	analyseData(std::string &, Player &);
  };
}

#endif // !__COMMANDMANAGER_HPP__
