/*
** make_team_tab.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/src
** 
** Made by Nathalie CAI
** Login   <nathalie.cai@epitech.eu>
** 
** Started on  Mon Jun 26 17:52:26 2017 Nathalie CAI
** Last update Wed Jun 28 13:34:05 2017 Nathalie CAI
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

static int	is_in_tab(char **tab, char *target)
{
  int   i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      if (strcmp(tab[i], target) == 0)
	return (1);
      i++;
    }
  return (0);
}

char	**team_tab(int ac, char **av)
{
  int   i;
  int   j;
  char  **tab;

  i = 0;
  while (i < ac && strcmp(av[i], "-n") != 0)
    i++;
  tab = NULL;
  j = 0;
  while (++i < ac && strncmp(av[i], "-", 1) != 0)
    {
      if (is_in_tab(tab, av[i]) == 0)
	{
	  if ((tab = realloc(tab, sizeof(char *) * (j + 2))) == NULL)
	    return (NULL);
	  tab[j] = av[i];
	  tab[j + 1] = NULL;
	}
      j++;
    }
  return (tab);
}
