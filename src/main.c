/*
** main.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/src
** 
** Made by Nathalie CAI
** Login   <abel@epitech.eu>
** 
** Started on  Wed Jun 21 11:33:09 2017 Nathalie CAI
** Last update Wed Jun 21 16:39:13 2017 Nathalie CAI
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include "all_structs.h"

int	main(int ac, char **av)
{
  t_data *data;

  data = malloc(sizeof (t_data));
  if ((data = init_data(data, ac, av)) == NULL)
    return (-1);
  print_data(data);
}
