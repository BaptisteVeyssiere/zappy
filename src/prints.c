/*
** prints.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/src
**
** Made by Nathalie CAI
** Login   <nathalie.cai@epitech.eu>
**
** Started on  Wed Jun 21 15:44:39 2017 Nathalie CAI
** Last update Mon Jun 26 19:52:21 2017 Nathalie CAI
*/

#include <stdio.h>
#include "server.h"

void	print_map(t_data *data)
{
  unsigned int	i;
  unsigned int	j;
  int	k;

  i = 0;
  while (i < data->height)
    {
      j = 0;
      while (j < data->width)
	{
	  k = 0;
	  printf("[%d:%d] ", i, j);
	  while (k < ITEMNBR)
	    {
	      printf("%d ", data->map[i][j].item[k]);
	      k++;
	    }
	  printf("\n");
	  j++;
	}
      i++;
    }
}

void	print_data(t_data *data)
{
  unsigned int i;

  printf("freq = %d\n", data->freq);
  printf("width = %d\n", data->width);
  printf("height = %d\n", data->height);
  printf("nbr_teams = %d\n", data->nbr_teams);
  i = 0;
  while (i < data->nbr_teams)
    {
      printf("team name %d %s\n", i, data->team_list[i]->name);
      i++;
    }
  printf("player_limit = %d\n", data->player_limit);
  printf("seed = %d\n", data->seed);
}
