/*
** execute_actions.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Tue Jun 27 14:40:30 2017 Baptiste Veyssiere
** Last update Tue Jun 27 15:51:18 2017 Baptiste Veyssiere
*/

#include "server.h"

static int	execute_player_action(t_player *tmp, t_data *data)
{
  tmp = tmp;
  data = data;
  return (0);
}

int	execute_actions(t_data *data)
{
  t_player	*tmp;

  tmp = data->players_root;
  while (tmp)
    {
      if (execute_player_action(tmp, data) == -1)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}
