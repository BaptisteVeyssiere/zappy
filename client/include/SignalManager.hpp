//
// SignalManager.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Jun 26 10:47:11 2017 Nathan Scutari
// Last update Mon Jun 26 11:10:21 2017 Nathan Scutari
//

#ifndef __SIGNALMANAGER_HPP__
# define __SIGNALMANAGER_HPP__

#include <signal.h>
#include <sys/signalfd.h>

namespace zappy
{
  class	SignalManager
  {
  private:
    int	sfd;

  private:
    SignalManager(SignalManager &other);
    SignalManager	&operator=(SignalManager &other);

  public:
    SignalManager();
    ~SignalManager();

  public:
    int		getSignalFd() const;
    void	checkSignal() const;
  };
}

#endif // !__SIGNALMANAGER_HPP__
