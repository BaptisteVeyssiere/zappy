//
// Regroup.hpp for Regroup  in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jul  1 17:16:10 2017 vigner_g
// Last update Sat Jul  1 23:35:09 2017 vigner_g
//

#ifndef	__REGROUP_HPP__
# define __REGROUP_HPP__

#include <vector>
#include <string>

namespace zappy
{
  class	Regroup
  {
  public:
    Regroup();
    ~Regroup();

  private:
    Regroup(Regroup &other);
    Regroup	&operator=(Regroup &other);

  private:
    bool		elevating; //appel les autres joueurs
    int			joining; //id du joueur à joindre
    int			direction;//direction du joueur à rejoindre
    std::vector<int>	ids;//liste des ids à appeler

  public:
    bool		isElevating();
    void       		startElevating();
    void		stopElevating();
    int			getJoining();
    void       		setJoining(int id);
    void       		stopJoining();
    int			getDirection();
    void		setDirection(int dir);
    std::vector<int>	&getIDS();
    int			howManyFree();
    void		addID(int id);
    void		resetIDS();
  };
}

#endif // !__REGROUP_HPP__
