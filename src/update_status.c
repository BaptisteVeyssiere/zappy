/*
** update_status.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Mon Jun 26 15:45:08 2017 Baptiste Veyssiere
** Last update Fri Jun 30 14:55:50 2017 Baptiste Veyssiere
*/

#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include "server.h"

int			update_egg_status(t_data *data)
{
  struct timeval	tv;
  t_egg			*tmp;
  unsigned long int	current_time;
  int			i;

  tmp = data->eggs;
  gettimeofday(&tv, NULL);
  current_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
  while (tmp)
    {
      if (tmp->ready == 0 && current_time > tmp->timer)
	{
	  if (eht(data, tmp) == -1)
	    return (-1);
	  tmp->ready = 1;
	  i = -1;
	  while (data->team_list && data->team_list[++i])
	    if (strcmp(data->team_list[i]->name, tmp->team) == 0)
	      ++(data->team_list[i]->free_slots);
	}
      tmp = tmp->next;
    }
  return (0);
}

void			update_action_status(t_data *data)
{
  t_player		*tmp;
  struct timeval	tv;
  unsigned long int	current_time;

  tmp = data->players_root;
  if (gettimeofday(&tv, NULL) == -1)
    write_error(__FILE__, __func__, __LINE__, 0);
  current_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
  while (tmp)
    {
      if (tmp->action && current_time > tmp->action->timer)
	tmp->action->ready = 1;
      tmp = tmp->next;
    }
}
