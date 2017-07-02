/*
** execute_actions.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_20
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Tue Jun 27 14:40:30 2017 Baptiste Veyssiere
** Last update Sun Jul  2 02:55:37 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "server.h"

void		set_action_timer(t_action *action, int duration,
				 unsigned int freq)
{
  struct timeval	tv;

  gettimeofday(&tv, NULL);
  action->timer = tv.tv_sec * 1000 + tv.tv_usec / 1000 +
    ((float)duration / (float)freq) * 1000.0;
}

static bool	check_incant(t_player *tmp, t_data *data)
{
  static  bool    (*incant[7])(t_data *, t_player *) =
    {
      upgrade_to_lvl2,
      upgrade_to_lvl3,
      upgrade_to_lvl4,
      upgrade_to_lvl5,
      upgrade_to_lvl6,
      upgrade_to_lvl7,
      upgrade_to_lvl8
    };

  if (!tmp->action->incant_checked && (tmp->action->incant_checked = 1) == 1)
    if (strncmp(tmp->action->action, "Incantation", 11) == 0)
      {
	if (!(incant[tmp->level - 1])(data, tmp))
	  {
	    if (add_to_ilist(tmp, tmp) == -1)
	      return (-1);
	    return (socket_write(tmp->fd, "ko\n") != -1);
	  }
	else
	  return (incant_underway(data, tmp));
      }
  return (true);
}

static bool	execute_player_action(t_player *tmp, t_data *data)
{
  static  t_act actions[] =
    {
      {"Forward", action_forward, 7},
      {"Right", action_right, 7},
      {"Left", action_left, 7},
      {"Look", action_look, 7},
      {"Inventory", action_inventory, 1},
      {"Broadcast ", action_broadcast, 7},
      {"Connect_nbr", action_connect_nbr, 0},
      {"Fork", action_fork, 42},
      {"Eject", action_eject, 7},
      {"Take ", action_take, 7},
      {"Set ", action_set, 7},
      {"Incantation", action_incantation, 300}
    };

  if (tmp->action->ready)
    {
      if (executer(actions, tmp, data) == false)
	return (false);
    }
  else if (!check_incant(tmp, data))
    return (false);
  return (true);
}

int	execute_actions(t_data *data)
{
  t_player	*tmp;

  tmp = data->players_root;
  while (tmp)
    {
      if (tmp->action && !execute_player_action(tmp, data))
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}
