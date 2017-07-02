/*
** actions.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sat Jul  1 01:51:22 2017 Baptiste Veyssiere
** Last update Sat Jul  1 22:24:04 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

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
          if (duration == -2)
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

int	stop_command(t_player *player, char *command)
{
  if (socket_write(player->fd, "ko\n") == -1)
    return (-1);
  free(command);
  return (0);
}

int	executer(t_act *actions, t_player *tmp, t_data *data)
{
  int	i;
  bool	ret;

  i = -1;
  ret = true;
  while (++i < ACTION_NBR &&
	 strncmp(tmp->action->action, actions[i].name,
		 strlen(actions[i].name)) != 0);
  if (i < ACTION_NBR)
    {
      printf("Command by %d: %s\n", tmp->fd, actions[i].name);
      ret = (actions[i].func)(data, tmp,
			      tmp->action->action + strlen(actions[i].name));
    }
  if (!ret || !get_next_valid_action(data, tmp))
    return (false);
  return (true);
}
