/*
** execute_actions.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Tue Jun 27 14:40:30 2017 Baptiste Veyssiere
** Last update Thu Jun 29 12:17:04 2017 Mathis Guilbon
*/

#include "action.h"
#include "incantation.h"
#include <stdio.h>

void		set_action_timer(t_action *action, int duration, unsigned int freq)
{
  struct timeval	tv;

  gettimeofday(&tv, NULL);
  action->timer = tv.tv_sec * 1000 + tv.tv_usec / 1000 +
    ((float)duration / (float)freq) * 1000.0;
}

static bool	get_next_valid_action(t_data *data, t_player *tmp)
{
  int		duration;
  int		cont;
  t_action	*act;

  cont = 1;
  while (cont-- > 0)
    {
      act = tmp->action;
      tmp->action = tmp->action->next;
      free(act->action);
      free(act);
      if (tmp->action != NULL)
	{
	  duration = get_command_duration(tmp->action->action);
	  if (duration == 0)
	    {
	      ++cont;
	      if (socket_write(tmp->fd, "ko\n") == -1)
		return (false);
	    }
	  else
	    set_action_timer(tmp->action, duration, data->freq);
	}
    }
  return (true);
}

static bool	check_incant(t_player *tmp, t_data *data)
{
  bool		ret;

  if (!tmp->action->incant_checked)
    {
      tmp->action->incant_checked = 1;
      if (strncmp(tmp->action->action, "Incantation", 11) == 0)
	{
	  ret = (incant[tmp->level - 1])(data, tmp);
	  if (socket_write(tmp->fd, ret ? "Elevation underway\n" : "ko\n") == -1)
	    return (false);
	}
    }
  return (true);
}

static bool	execute_player_action(t_player *tmp, t_data *data)
{
  int		i;
  bool		ret;

  ret = true;
  if (tmp->action->ready)
    {
      i = -1;
      while (++i < ACTION_NBR &&
	     strncmp(tmp->action->action, actions[i].name,
		     strlen(actions[i].name)) != 0);
      if (i < ACTION_NBR)
	ret = (actions[i].func)(data, tmp,
				tmp->action->action + strlen(actions[i].name));
      if (!ret || !get_next_valid_action(data, tmp))
	return (false);
      print_map(data);
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