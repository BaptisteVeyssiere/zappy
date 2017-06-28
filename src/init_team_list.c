/*
** init_team_list.c for Project in nathalie/rendu/network/PSU_2016_zappy/src
** 
** Made by Nathalie CAI
** Login   <nathalie.cai@epitech.eu>
** 
** Started on  Mon Jun 26 16:38:22 2017 Nathalie CAI
** Last update Wed Jun 28 15:23:23 2017 Nathalie CAI
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

static  t_data	*init_nbr_teams(t_data *data, char **tab)
{
  int	i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    i++;
  if ((data->nbr_teams = i) == 0)
    return (NULL);
  return (data);
}

static	t_data	*init_team(t_data *data, char **tab, int i, int j)
{
  if ((data->team_list[i]->name = strdup(tab[j])) == NULL)
    return (NULL);
  data->team_list[i]->free_slots = data->player_limit;
  data->team_list[i]->highest_level = 1;
  return (data);
}

static t_data	*init_team_loop(t_data *data, char **tab)
{
  int           j;
  unsigned int  i;

  i = -1;
  j = 0;
  while (++i < data->nbr_teams)
    {
      if ((data->team_list[i] = malloc(sizeof(t_team))) == NULL)
	return (NULL);
      bzero(data->team_list[i], sizeof(t_team));
      if ((data = init_team(data, tab, i, j++)) == NULL)
	return (NULL);
    }
  data->team_list[i] = NULL;
  return (data);
}

t_data	*init_team_list(t_data *data, int ac, char **av)
{
  char          **tab;

  if ((tab = team_tab(ac, av)) == NULL)
    {
      data->team_list = NULL;
      data->nbr_teams = 0;
      return (data);
    }
  if ((data = init_nbr_teams(data, tab)) == NULL)
    return (NULL);
  if ((data->team_list =
       malloc(sizeof(t_team *) * (data->nbr_teams + 1))) == NULL)
    return (NULL);
  bzero(data->team_list, sizeof(t_team *) * (data->nbr_teams + 1));
  if ((data = init_team_loop(data, tab)) == NULL)
    return (NULL);
  free(tab);
  return (data);
}
