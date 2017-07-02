/*
** free_tools.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_za
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Jun 25 22:25:23 2017 Baptiste Veyssiere
** Last update Sun Jul  2 18:59:10 2017 Baptiste Veyssiere
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

void		remove_from_incantation(t_data *data, t_player *player)
{
  t_player	*tmp;
  t_incantation	*incant;
  t_incantation	*prev;
  t_incantation	*next;

  tmp = data->players_root;
  while (tmp)
    {
      if (tmp->action && tmp->action->list && (prev = NULL) == NULL)
	{
	  incant = tmp->action->list;
	  while (incant)
	    {
	      next = incant->next;
	      if (incant->player == player && prev == NULL)
		tmp->action->list = next;
	      else if (incant->player == player)
		prev->next = next;
	      else
		prev = incant;
	      incant = next;
	    }
	}
      tmp = tmp->next;
    }
}
