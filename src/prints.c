/*
** prints.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/src
**
** Made by Nathalie CAI
** Login   <nathalie.cai@epitech.eu>
**
** Started on  Wed Jun 21 15:44:39 2017 Nathalie CAI
** Last update Tue Jun 27 17:43:48 2017 Nathalie CAI
*/

#include <stdio.h>
#include "server.h"

int	print_usage(void)
{
  printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
  printf("\tport\tis the port number\n");
  printf("\twidth\tis the width of the world\n");
  printf("\theight\tis the height of the world\n");
  printf("\tnameX\tis the name of the team X\n");
  printf("\tclientsNb\tis the number of authorized clients per team\n");
  printf("\tfreq\tis the reciprocal of time unit for execution of actions\n");
  return (0);
}

void	print_map(t_data *data)
{
  unsigned int	i;
  unsigned int	j;
  int	k;

  i = -1;
  while (++i < data->height)
    {
      j = -1;
      while (++j < data->width)
	{
	  k = -1;
	  printf("[%d:%d] ", i, j);
	  while (++k < ITEMNBR)
	    {
	      printf("%d ", data->map[i][j].item[k]);
	    }
	  printf("\n");
	}
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
