/*
** update_player_action.c for Project-Master in /home/veyssi_b/rendu/tek2/PS
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Jun 25 21:12:34 2017 Baptiste Veyssiere
** Last update Sat Jul  1 23:58:08 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

static int	get_action_nbr(t_player *player)
{
  int		nbr;
  t_action	*tmp;

  nbr = 0;
  tmp = player->action;
  while (tmp)
    {
      ++nbr;
      tmp = tmp->next;
    }
  return (nbr);
}

static void		init_action(char *command, int duration,
				    unsigned int freq, t_action *action)
{
  action->next = NULL;
  action->ready = 0;
  action->action = command;
  action->incant_checked = 0;
  action->list = NULL;
  set_action_timer(action, duration, freq);
}

static int		try_add_action(t_player *player,
				       t_data *data, char *command)
{
  t_action		*action;
  int			duration;
  t_action		*tmp;

  if ((duration = get_command_duration(command)) == -1 ||
      get_action_nbr(player) == 10)
    {
      if (duration != -1 && (duration = 0) == 0)
	free(command);
      return (duration);
    }
  tmp = player->action;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (duration == -2 && (duration = 0) == 0 && !tmp)
    return (stop_command(player, command));
  if (!(action = malloc(sizeof(t_action))))
    return (write_error(__FILE__, __func__, __LINE__, -1));
  init_action(command, duration, data->freq, action);
  if (!tmp)
    player->action = action;
  else
    tmp->next = action;
  return (0);
}

static int	update_actions(t_player *player, t_data *data)
{
  int		ret;
  int		is_cmd;
  char		*command;

  if ((ret = read_socket(player->fd, player->ringbuffer)) == -1)
    {
      if (free_player(player, data) == -1)
	return (-1);
      return (1);
    }
  while ((is_cmd = 0) == 0 &&
	 (command = check_ring(player->ringbuffer, 0, &is_cmd)))
    {
      printf("<%s>\n", command);
      if (try_add_action(player, data, command) == -1)
	{
	  free(command);
	  return (-1);
	}
    }
  return (is_cmd != 0 ? -1 : 0);
}

int	update_player_action(t_data *data, fd_set *set)
{
  t_player	*elem;
  t_player	*tmp;
  t_player	*prev;
  int		ret;

  elem = data->players_root;
  prev = NULL;
  while (elem)
    {
      ret = 0;
      tmp = elem->next;
      if (FD_ISSET(elem->fd, set))
	{
	  if ((ret = update_actions(elem, data)) == -1)
	    return (-1);
	  if (ret == 1 && prev != NULL)
	    prev->next = tmp;
	  else if (ret == 1)
	    data->players_root = tmp;
	}
      if (ret == 0)
	prev = elem;
      elem = tmp;
    }
  return (0);
}
