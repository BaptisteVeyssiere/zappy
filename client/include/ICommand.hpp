//
// ICommand.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 14:03:46 2017 Nathan Scutari
// Last update Fri Jun 23 16:52:57 2017 Nathan Scutari
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
    //renvoie la chaine complete
    void	addArg();
    //rajouet un argument
    void	getArg(int);
    //recupere argument x
    void	getResponse(Player &, std::string &);
    //recupere la reponse du serveur(ok / ko / inventaire (dépend de la commande), stock dans player(qui doit contenir les infos sur le joueur (inventaire) (vision) ...))
  }
}

#endif // __ICOMMAND_HPP__
