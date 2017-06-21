/*
** main_loop.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 21 15:33:39 2017 Baptiste Veyssiere
** Last update Wed Jun 21 15:38:47 2017 Baptiste Veyssiere
*/

#include <unistd.h>
#include "server.h"

int	main_loop(t_data *data)
{
  while (1)
    {
      // Execution des actions des joueurs (boucle)
      // Attribution d'une action aux joueurs avec buffer < 10 actions
      // Update de la waiting queue
      // Décrémentation de la timelimit des oeufs
      usleep(100);
    }
  // Free de la structure data
  return (0);
}
