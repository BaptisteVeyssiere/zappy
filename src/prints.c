/*
** prints.c for Project-Master in nathalie/rendu/network/PSU_2016_zappy/src
**
** Made by Nathalie CAI
** Login   <nathalie.cai@epitech.eu>
**
** Started on  Wed Jun 21 15:44:39 2017 Nathalie CAI
** Last update Wed Jun 28 13:49:34 2017 Nathalie CAI
*/

#include <stdio.h>
#include "server.h"

int	print_error_param(char *msg)
{
  fprintf(stderr, "%s", msg);
  return (-1);
}

int	print_usage(void)
{
  printf("USAGE: ./zappy_server -p port -x width -y height");
  printf(" -n name1 name2 ... -c clientsNb -f freq\n");
  printf("\tport\t\tis the port number\n");
  printf("\twidth\t\tis the width of the world\n");
  printf("\theight\t\tis the height of the world\n");
  printf("\tnameX\t\tis the name of the team X\n");
  printf("\tclientsNb\tis the number of authorized clients per team\n");
  printf("\tfreq\t\tis the reciprocal of time unit for execution of actions\n");
  return (0);
}

int	print_param(void)
{
  fprintf(stderr, "Some parameters are missing or wrong, please check them.\n");
  print_usage();
  return (-1);
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

  printf("The server launched with parameters:\n");
  printf("port: %d\n", data->port);
  printf("map of size: %d * %d\n", data->width, data->height);
  printf("number of teams: %d with name:", data->nbr_teams);
  i = 0;
  while (i < data->nbr_teams)
    {
      printf(" %s", data->team_list[i]->name);
      i++;
    }
  printf("\nnumber of authorized clients per team: %d\n", data->player_limit);
  printf("reciprocal of time unit for execution of actions: %d\n", data->freq);
  printf("seed for randomization of the ressources: %d\n", data->seed);
}
