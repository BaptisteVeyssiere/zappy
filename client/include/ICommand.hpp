//
// ICommand.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Fri Jun 23 14:03:46 2017 Nathan Scutari
// Last update Sun Jul  2 18:37:03 2017 Nathan Scutari
//

#ifndef __ICOMMAND_HPP__
# define __ICOMMAND_HPP__

#include "Player.hpp"

#define UNUSED __attribute__((unused))

namespace zappy
{
  class Player;
}

namespace zappy
{
  class	ICommand
  {
  private:
    ICommand	&operator=(ICommand &other);

  public:
    virtual ~ICommand() {};

  public:
    virtual std::string	&getStr() = 0;
    //renvoie la chaine complete (pour envoyer la commande au server)
    virtual void	addArg(std::string) = 0;
    //rajouet un argument
    virtual bool	getResponse(Player &, std::string &) = 0;
    //recupere la reponse du serveur(ok / ko / inventaire (dépend de la commande), stock dans player(qui doit contenir les infos sur le joueur (inventaire) (vision) ...))
  };
}

#endif // __ICOMMAND_HPP__
