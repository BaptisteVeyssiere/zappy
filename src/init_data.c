/*
** init_data.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/src
**
** Made by Nathalie CAI
** Login   <abel@epitech.eu>
**
** Started on  Wed Jun 21 12:12:58 2017 Nathalie CAI
** Last update Tue Jun 27 18:47:51 2017 Nathalie CAI
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "server.h"

t_data	*init_data(t_data *data, int ac, char **av)
{
  data->players_root = NULL;
  data->network = NULL;
  data->queue = NULL;
  data->freq = get_uint(ac, av, "-f");
  if ((data->freq != 0 && data->freq < 2) || data->freq > 1000)
    return (NULL);
  if (data->freq == 0)
    data->freq = 100;
  if ((data->width = get_uint(ac, av, "-x")) == 0
      || data->width < 10 || data->width > 30)
    return (NULL);
  if ((data->height = get_uint(ac, av, "-y")) == 0
      || data->height < 10 || data->height > 30)
    return (NULL);
  if ((data->port = get_uint(ac, av, "-p")) == 0)
    return (NULL);
  if ((data->seed = get_uint(ac, av, "-s")) == 0)
    data->seed = time(NULL);
  if ((data = init_map(data)) == NULL)
    return (NULL);
  if ((data->player_limit = get_uint(ac, av, "-c")) == 0)
    return (NULL);
  if ((data = init_team_list(data, ac, av)) == NULL)
    return (NULL);
  data->eggs = NULL;
  data->pid = 0;
  data->eid = 0;
  return (data);
}
