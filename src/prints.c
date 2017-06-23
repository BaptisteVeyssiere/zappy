/*
** prints.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/src
** 
** Made by Nathalie CAI
** Login   <abel@epitech.eu>
** 
** Started on  Wed Jun 21 15:44:39 2017 Nathalie CAI
** Last update Fri Jun 23 17:02:19 2017 Nathalie CAI
*/

#include "server.h"
#include "all_structs.h"
#include <stdio.h>

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
}
