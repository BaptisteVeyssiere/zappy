/*
** free_tools.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_za
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Jun 25 22:25:23 2017 Baptiste Veyssiere
** Last update Sun Jul  2 02:40:16 2017 Baptiste Veyssiere
*/

#include <stdlib.h>
#include "server.h"

void		free_ilist(t_action *action)
{
  t_incantation	*tmp;
  t_incantation	*next;

  tmp = action->list;
  while (tmp)
    {
      next = tmp->next;
      free(tmp);
      tmp = next;
    }
}

void		free_actions(t_action *action)
{
  t_action	*tmp;

  while (action)
    {
      tmp = action->next;
      free(action->action);
      free_ilist(action);
      free(action);
      action = tmp;
    }
}
