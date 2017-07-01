/*
** make_team_tab.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/src
**
** Made by Nathalie CAI
** Login   <nathalie.cai@epitech.eu>
**
** Started on  Mon Jun 26 17:52:26 2017 Nathalie CAI
** Last update Fri Jun 30 18:09:02 2017 Baptiste Veyssiere
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

static char	**default_team(void)
{
  char		**tab;

  if (!(tab = malloc(sizeof(char*) * 5)))
    return (NULL);
  tab[0] = "team1";
  tab[1] = "team2";
  tab[2] = "team3";
  tab[3] = "team4";
  tab[4] = NULL;
  return (tab);
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
  i = -1;
  while (tab && tab[++i]);
  if (i < 1)
    return (default_team());
  return (tab);
}
