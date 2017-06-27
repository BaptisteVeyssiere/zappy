//
// Parser.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Sat Jun 24 16:21:52 2017 Nathan Scutari
// Last update Sat Jun 24 17:22:23 2017 Nathan Scutari
//

#ifndef __PARSER_HPP__
# define __PARSER_HPP__

#include <string>

namespace zappy
{
  class Parser
  {
  private:
    std::string	machine;
    std::string	port;
    std::string	team;

  private:
    Parser(Parser &other);
    Parser	&operator=(Parser &other);

  public:
    Parser();
    ~Parser();

  public:
    void	parseArgs(int ac, char **av);
    std::string	&getMachine();
    std::string	&getPort();
    std::string	&getTeam();
  };
}

#endif // !__PARSER_HPP__
