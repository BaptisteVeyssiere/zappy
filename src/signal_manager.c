/*
** signal_manager.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Fri Jun 23 14:19:02 2017 Baptiste Veyssiere
** Last update Fri Jun 23 14:28:49 2017 Baptiste Veyssiere
*/

#include <signal.h>
#include <string.h>
#include "server.h"

int				check_signal(int fd)
{
  struct signalfd_siginfo	si;

  if (read(fd, &si, sizeof(si)) < (int)sizeof(si))
    return (write_error(__FILE__, __func__, __LINE__, -1));
  if (si.ssi_signo == SIGINT || si.ssi_signo == SIGTERM)
    {
      if (write(2, SIGNAL_CAUGHT, strlen(SIGNAL_CAUGHT)) <
	  (int)strlen(SIGNAL_CAUGHT))
	return (write_error(__FILE__, __func__, __LINE__, -1));
      return (2);
    }
  return (0);
}

int		create_signal_fd(void)
{
  int		fd;
  sigset_t	mask;

  if (sigemptyset(&mask) == -1 ||
      sigaddset(&mask, SIGINT) == -1 ||
      sigaddset(&mask, SIGTERM) == -1 ||
      sigprocmask(SIG_BLOCK, &mask, NULL) < 0 ||
      (fd = signalfd(-1, &mask, 0)) < 0)
    return (write_error(__FILE__, __func__, __LINE__, -1));
  return (fd);
}
