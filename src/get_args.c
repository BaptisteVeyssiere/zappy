/*
** get_args.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zapp
**
** Made by Nathalie CAI
** Login   <abel@epitech.eu>
**
** Started on  Wed Jun 21 11:31:11 2017 Nathalie CAI
** Last update Sat Jul  1 15:07:59 2017 Baptiste Veyssiere
*/

#include <string.h>
#include <stdlib.h>

unsigned int	get_uint(int ac, char **av, char *target)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      if (strcmp(av[i], target) == 0 && i + 1 < ac)
	{
	  return (strtoul(av[i + 1], NULL, 10));
	}
      i++;
    }
  return (0);
}
