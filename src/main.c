/*
** main.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/src
**
** Made by Nathalie CAI
** Login   <abel@epitech.eu>
**
** Started on  Wed Jun 21 11:33:09 2017 Nathalie CAI
** Last update Sat Jun 24 15:56:44 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

int		main(int ac, char **av)
{
  t_data	*data;

  if (!(data = malloc(sizeof(t_data))))
    return (write_error(__FILE__, __func__, __LINE__, 84));
  if ((data = init_data(data, ac, av)) == NULL)
    return (-1);
  print_data(data);
  return (main_loop(data));
}
