/*
** main.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/src
**
** Made by Nathalie CAI
** Login   <abel@epitech.eu>
**
** Started on  Wed Jun 21 11:33:09 2017 Nathalie CAI
** Last update Wed Jun 28 17:34:12 2017 Nathalie CAI
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

int		main(int ac, char **av)
{
  t_data	*data;

  if (ac > 1 && strcmp(av[1], "-help") == 0)
    return (print_usage());
  if (check_args(ac, av) == -1)
    return (-1);
  if (!(data = malloc(sizeof(t_data))))
    return (write_error(__FILE__, __func__, __LINE__, 84));
  if ((data = init_data(data, ac, av)) == NULL)
    return (-1);
  print_data(data);
  print_map_ressources(data);
  print_map(data);
  return (main_loop(data));
}
