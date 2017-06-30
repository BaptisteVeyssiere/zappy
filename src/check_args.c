/*
** check_args.c for Project-Master in nathalie/rendu/network/PSU_2016_zappy/src
**
** Made by Nathalie CAI
** Login   <nathalie.cai@epitech.eu>
**
** Started on  Wed Jun 28 12:54:55 2017 Nathalie CAI
** Last update Fri Jun 30 14:57:08 2017 Baptiste Veyssiere
*/

#include <string.h>
#include <stdio.h>
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

static char	*check_options(int ac, char **av)
{
  int	i;
  int	j;
  int	a;
  char	*options[] =
    {
      "-p", "-x", "-y", "-n", "-c", "-f"
    };

  i = 0;
  while (i < ac)
    {
      if (strncmp(av[i], "-", 1) == 0)
	{
	  j = 0;
	  a = 0;
	  while (j < 6 && a == 0)
	    {
	      if (strncmp(av[i], options[j], strlen(options[j])) != 0)
		j++;
	      else
		a = 1;
	    }
	  if (a == 0)
	    return (av[i]);
	}
      i++;
    }
  return (NULL);
}

int	check_args(int ac, char **av)
{
  unsigned int	width;
  unsigned int	height;
  unsigned int	freq;
  unsigned int	player_limit;
  unsigned int	port;
  char		*option;

  if ((option = check_options(ac, av)) != NULL)
    {
      fprintf(stderr, "%s ", option);
      return (print_error_param("is not a known option.\n"));
    }
  freq = get_uint(ac, av, "-f");
  player_limit = get_uint(ac, av, "-c");
  if (((width = get_uint(ac, av, "-x")) != 0 && width < 10) || width > 30)
    return (print_error_param("-x should be between 10 and 30.\n"));
  if (((height = get_uint(ac, av, "-y")) != 0 && height < 10) || height > 30)
    return (print_error_param("-y should be between 10 and 30.\n"));
  if ((freq != 0 && freq < 2) || freq > 1000)
    return (print_error_param("-f should be between 2 and 1000.\n"));
  if ((player_limit != 0 && player_limit < 2) || player_limit > 1000)
    return (print_error_param("-c should be between 1 and 50.\n"));
  if (((port = get_uint(ac, av, "-p")) != 0 && port < 1025) || port > 65535)
    return (print_error_param("-p should be between 1025 and 65535.\n"));
  return (check_team_names(ac, av));
}
