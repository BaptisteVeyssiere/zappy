//
// SignalManager.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client/include
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Mon Jun 26 11:00:03 2017 Nathan Scutari
// Last update Mon Jun 26 11:16:16 2017 Nathan Scutari
//

#include <unistd.h>
#include "Exception.hpp"
#include "SignalManager.hpp"

zappy::SignalManager::SignalManager()
{
  sigset_t	mask;

  sigemptyset(&mask);
  sigaddset(&mask, SIGINT);
  sigaddset(&mask, SIGTERM);
  sigaddset(&mask, SIGPIPE);
  if (sigprocmask(SIG_BLOCK, &mask, NULL) < 0 ||
      (sfd = signalfd(-1, &mask, 0)) < 0)
    throw client_exception("Could not init signal handling", __LINE__, __FILE__);
}

zappy::SignalManager::~SignalManager()
{

}

void	zappy::SignalManager::checkSignal() const
{
  struct signalfd_siginfo	si;

  read(sfd, &si, sizeof(si));
  if (si.ssi_signo == SIGINT || si.ssi_signo == SIGTERM)
    throw client_exception("Caught killing signal, closing", __LINE__, __FILE__);
  else if (si.ssi_signo == SIGPIPE)
    return ;
}

int	zappy::SignalManager::getSignalFd() const
{
  return (sfd);
}
