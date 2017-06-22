/*
** init_data.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/src
** 
** Made by Nathalie CAI
** Login   <abel@epitech.eu>
** 
** Started on  Wed Jun 21 12:12:58 2017 Nathalie CAI
** Last update Thu Jun 22 10:37:49 2017 Nathalie CAI
*/

#include "all_structs.h"
#include "server.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static t_data	*init_map(t_data *data)
{
  unsigned int	i;

  if ((data->map = malloc(sizeof (t_items *) * data->height)) == NULL)
    return (NULL);
  bzero(data->map, sizeof (t_items*));
  i = 0;
  while (i < data->height)
    {
      if ((data->map[i] = malloc(sizeof (t_items) * data->width)) == NULL)
	return (NULL);
      bzero(data->map[i], sizeof (t_items));
      i++;
    }
  return (data);
}

static int	get_nbr_of_teams(int ac, char **av)
{
  int	j;
  int   i;

  i = 1;
  while (i < ac)
    {
      if (i + 1 < ac && strcmp(av[i], "-n") == 0)
	{
	  j = 0;
	  i++;
	  while (i < ac && strncmp(av[i], "-", 1) != 0)
	    {
	      j++;
	      i++;
	    }
	  return (j);
	}
      i++;
    }
  return (0);
}

static t_data	*init_team_list(t_data *data, int ac, char **av)
{
  int	j;
  unsigned  int	i;

  if ((data->team_list = malloc(sizeof (t_team) * data->nbr_teams)) == NULL)
    return (NULL);
  bzero(data->team_list, sizeof (t_team) * data->nbr_teams);
  j = 0;
  while (strcmp(av[j], "-n") != 0 && j < ac)
    j++;
  j++;
  i = 0;
  while (i < data->nbr_teams)
    {
      if ((data->team_list[i].name = strdup(av[j])) == NULL)
      	return (NULL);
      data->team_list[i].free_slots = data->player_limit;
      data->team_list[i].highest_level = 1;
      j++;
      i++;
    }
  return (data);
}

t_data	*init_data(t_data *data, int ac, char **av)
{
  data->players_root = NULL;
  if ((data->freq = get_uint(ac, av, "-f")) == 0)
    data->freq = 100;
  if ((data->width = get_uint(ac, av, "-x")) == 0)
    return (NULL);
  if ((data->height = get_uint(ac, av, "-y")) == 0)
    return (NULL);
  if ((data = init_map(data)) == NULL)
    return (NULL);
  if ((data->player_limit = get_uint(ac, av, "-c")) == 0)
    return (NULL);
  if ((data->nbr_teams = get_nbr_of_teams(ac, av)) == 0)
    return (NULL);
  if ((data = init_team_list(data, ac, av)) == NULL)
    return (NULL);
  data->eggs = NULL;
  if ((data->seed = get_uint(ac, av, "-s")) == 0)
    data->seed = time(NULL);
  return (data);
}
