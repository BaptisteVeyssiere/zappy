/*
** update_egg_status.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Mon Jun 26 14:16:21 2017 Baptiste Veyssiere
** Last update Mon Jun 26 14:22:41 2017 Baptiste Veyssiere
*/

#include <sys/time.h>
#include <unistd.h>
#include "server.h"

void			update_egg_status(t_data *data)
{
  struct timeval	tv;
  t_egg			*tmp;
  int			current_time;

  tmp = data->eggs;
  gettimeofday(&tv, NULL);
  current_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
  while (tmp)
    {
      if (tmp->ready == 0 && current_time > tmp->timer)
	tmp->ready = 1;
      tmp = tmp->next;
    }
}
