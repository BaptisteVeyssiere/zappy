//
// ICommand.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 14:03:46 2017 Nathan Scutari
// Last update Fri Jun 23 16:47:39 2017 Nathan Scutari
//

#ifndef __ICOMMAND_HPP__
# define __ICOMMAND_HPP__

namespace zappy
{
  class	ICommand
  {
  private:
    ICommand(Icommand &other);
    ICommand	&operator=(ICommand &other);

  public:
    ICommand() {}
    virtual ~ICommand();

  public:
    std::string	&getStr();
    void	addArg();
    void	getArg(int);
    void	getResponse(Player &);
  }
}

#endif // __ICOMMAND_HPP__
