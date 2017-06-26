/*
** free_tools.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Jun 25 22:25:23 2017 Baptiste Veyssiere
** Last update Sun Jun 25 22:27:44 2017 Baptiste Veyssiere
*/

#include <stdlib.h>
#include "server.h"

void		free_actions(t_action *action)
{
  t_action	*tmp;

  while (action)
    {
      tmp = action->next;
      free(action->action);
      free(action);
      action = tmp;
    }
}
