/*
** get_args.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/src
** 
** Made by Nathalie CAI
** Login   <abel@epitech.eu>
** 
** Started on  Wed Jun 21 11:31:11 2017 Nathalie CAI
** Last update Wed Jun 21 15:53:54 2017 Nathalie CAI
*/

#include <string.h>
#include <stdlib.h>

unsigned int	get_port(int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      if (strcmp(av[i], "-n") == 0 && i + 1 < ac)
	{
	  return (strtoul(av[i + 1], NULL, 10));
	}
      i++;
    }
  return (0);
}

unsigned int	get_width(int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      if (strcmp(av[i], "-x") == 0 && i + 1 < ac)
	{
	  return (strtoul(av[i + 1], NULL, 10));
	}
      i++;
    }
  return (0);
}

unsigned int	get_height(int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      if (strcmp(av[i], "-y") == 0 && i + 1 < ac)
	{
	  return (strtoul(av[i + 1], NULL, 10));
	}
      i++;
    }
  return (0);
}

unsigned int	get_freq(int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      if (strcmp(av[i], "-f") == 0 && i + 1 < ac)
	{
	  return (strtoul(av[i + 1], NULL, 10));
	}
      i++;
    }
  return (0);
}

unsigned int	get_client_max(int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      if (strcmp(av[i], "-c") == 0 && i + 1 < ac)
	{
	  return (strtoul(av[i + 1], NULL, 10));
	}
      i++;
    }
  return (0);
}
