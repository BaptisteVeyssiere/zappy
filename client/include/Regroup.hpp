//
// Regroup.hpp for Regroup  in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jul  1 17:16:10 2017 vigner_g
// Last update Sun Jul  2 23:33:43 2017 Nathan Scutari
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
    bool		elevating;
    int			elevTimeout;
    int			joining;
    int			direction;
    std::vector<int>	ids;
    int			playerNbr;

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
    int			getElevTimeout();
    void		setElevTimeout(int nbr);
    void		decElevTimeout(int nbr = 1);
    void		setPlayerNbr(int);
    int			getPlayerNbr();
  };
}

#endif // !__REGROUP_HPP__
