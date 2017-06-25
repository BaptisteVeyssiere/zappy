/*
** update_player_action.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Jun 25 21:12:34 2017 Baptiste Veyssiere
** Last update Sun Jun 25 22:25:07 2017 Baptiste Veyssiere
*/

#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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

static int	get_command_duration(char *command, int fd)
{
  int		duration;
  static char	*command_list[12] =
    {
      "Forward\0", "Right\0", "Left\0", "Look\0", "Inventory\0", "Broadcast ",
      "Connect_nbr\0", "Fork\0", "Eject\0", "Take ", "Set ", "Incantation\0"
    };
  static int	command_duration[12] =
    {
      7, 7, 7, 7, 1, 7, 0, 42, 7, 7, 7, 300
    };
  int		i;

  i = -1;
  duration = -2;
  while (++i < 12)
    if (strncmp(command_list[i], command, strlen(command_list[i])) == 0)
      {
	duration = command_duration[i];
	i = 12;
      }
  if (duration == -2 && socket_write(fd, "ko\n") == -1)
    return (-1);
  return (duration);
}

static int		try_add_action(t_player *player, t_data *data, char *command)
{
  t_action		*action;
  int			duration;
  struct timeval	tv;
  t_action		*tmp;

  if ((duration = get_command_duration(command, player->fd)) < 0 ||
      get_action_nbr(player) == 10)
    {
      if (duration != -1 && (duration = 0) == 0)
	free(command);
      return (duration);
    }
  tmp = player->action;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (!(action = malloc(sizeof(t_action))))
    return (write_error(__FILE__, __func__, __LINE__, -1));
  action->next = NULL;
  action->action = command;
  gettimeofday(&tv, NULL);
  action->timer = tv.tv_sec * 1000 + tv.tv_usec / 1000 +
    ((float)duration / (float)data->freq) * 1000.0;
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
      FD_CLR(player->fd, data->network->set);
      free(player->inventory);
      free(player->team);
      free(player->pos);
      free(player->ringbuffer);
      free_actions(player->action);
      free(player);
      return (1);
    }
  is_cmd = 0;
  while ((command = check_ring(player->ringbuffer, 0, &is_cmd)))
    {
      printf("<%s>\n", command);
      if (try_add_action(player, data, command) == -1)
	{
	  free(command);
	  return (-1);
	}
      is_cmd = 0;
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
