/*
** check_args.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/src
** 
** Made by Nathalie CAI
** Login   <nathalie.cai@epitech.eu>
** 
** Started on  Wed Jun 28 12:54:55 2017 Nathalie CAI
** Last update Wed Jun 28 13:43:35 2017 Nathalie CAI
*/

#include <string.h>
#include "server.h"

static int	is_there_spaces(int ac, char **av, int i)
{
  while (++i < ac && strncmp(av[i], "-", 1) != 0)
    {
      if (strstr(av[i], " ") != NULL)
	return (1);
    }
  return (0);
}


static int	check_team_names(int ac, char **av)
{
  int	i;

  i = 0;
  while (i < ac && strcmp(av[i], "-n") != 0)
    i++;
  if (is_there_spaces(ac, av, i) == 1)
    return (print_error_param("-n team names should not contain spaces.\n"));
  return (0);
}

int	check_args(int ac, char **av)
{
  unsigned int	width;
  unsigned int	height;
  unsigned int	freq;
  unsigned int	player_limit;

  width = get_uint(ac, av, "-x");
  height = get_uint(ac, av, "-y");
  freq = get_uint(ac, av, "-f");
  player_limit = get_uint(ac, av, "-c");
  if ((width != 0 && width < 10) || width > 30)
    return (print_error_param("-x should be between 10 and 30.\n"));
  if ((height != 0 && height < 10) || height > 30)
    return (print_error_param("-y should be between 10 and 30.\n"));
  if ((freq != 0 && freq < 2) || freq > 1000)
    return (print_error_param("-f should be between 2 and 1000.\n"));
  if ((player_limit != 0 && player_limit < 2) || player_limit > 1000)
    return (print_error_param("-c should be between 1 and 50.\n"));
  return (check_team_names(ac, av));
  return (0);
}
