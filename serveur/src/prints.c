/*
** prints.c for Project-Master in nathalie/rendu/network/PSU_2016_zappy/src
**
** Made by Nathalie CAI
** Login   <nathalie.cai@epitech.eu>
**
** Started on  Wed Jun 21 15:44:39 2017 Nathalie CAI
** Last update Sun Jul  2 19:32:17 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include "server.h"

int	print_error_param(char *msg)
{
  fprintf(stderr, "%s\n", msg);
  print_usage();
  return (-1);
}

int	print_usage(void)
{
  if (printf("USAGE: ./zappy_server -p port -x width -y height") < 0 ||
      printf(" -n name1 name2 ... -c clientsNb -f freq -g graphic_port\n") < 0
      || printf("\tport\t\tis the port number\n") < 0 ||
      printf("\tgraphic_port\t\tis the graphic port number\n") < 0 ||
      printf("\twidth\t\tis the width of the world\n") < 0 ||
      printf("\theight\t\tis the height of the world\n") < 0 ||
      printf("\tnameX\t\tis the name of the team X\n") < 0 ||
      printf("\tclientsNb\tis the number of authorized clients per team\n") < 0
      || printf("\tfreq\t\tis the frequence for execution of actions\n") < 0)
    return (84);
  return (0);
}

void	print_map(t_data *data)
{
  unsigned int	i;
  unsigned int	j;

  i = -1;
  while (++i < data->width * 2 + 1)
    printf("-");
  printf("\n");
  i = -1;
  while (++i < data->height)
    {
      j = -1;
      printf("|");
      while (++j < data->width)
	{
	  if (data->map[i][j].players > 0)
	    printf("x|");
	  else
	    printf(" |");
	}
      printf("\n");
    }
  i = -1;
  while (++i < data->width * 2 + 1)
    printf("-");
  printf("\n");
}

void	print_map_ressources(t_data *data)
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
	  printf("[%d:%d]", i, j);
	  k = -1;
	  while (++k < ITEMNBR)
	    printf(" %d", data->map[i][j].item[k]);
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
