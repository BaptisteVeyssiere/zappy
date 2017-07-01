/*
** free_data.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sat Jun 24 15:17:39 2017 Baptiste Veyssiere
** Last update Fri Jun 30 18:55:52 2017 Baptiste Veyssiere
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "server.h"

static int	free_players(t_player *player)
{
  t_player	*tmp;
  t_action	*_tmp;
  t_action	*action;

  while (player)
    {
      tmp = player->next;
      free(player->inventory);
      free(player->team);
      free(player->pos);
      free(player->ringbuffer);
      action = player->action;
      while (action)
	{
	  _tmp = action->next;
	  free(action->action);
	  free(action);
	  action = _tmp;
	}
      if (player->fd > 2 && close(player->fd) == -1)
	return (write_error(__FILE__, __func__, __LINE__, -1));
      free(player);
      player = tmp;
    }
  return (0);
}

static int	free_network(t_network *network)
{
  int		i;

  i = -1;
  while (++i < 2)
    if (network->socket_fd[i] > 2 && close(network->socket_fd[i]) == -1)
      return (write_error(__FILE__, __func__, __LINE__, -1));
  free(network->set);
  if ((network->graphic_fd > 2 && close(network->graphic_fd) == -1) ||
      (network->signal_fd > 2 && close(network->signal_fd) == -1))
    return (write_error(__FILE__, __func__, __LINE__, -1));
  free(network->graphic_buffer);
  free(network);
  return (0);
}

static void	free_eggs(t_egg	*egg)
{
  t_egg		*tmp;

  while (egg)
    {
      tmp = egg->next;
      free(egg->team);
      free(egg->pos);
      free(egg);
      egg = tmp;
    }
}

static int		free_queue(t_waiting_queue *queue)
{
  t_waiting_queue	*tmp;

  while (queue)
    {
      tmp = queue->next;
      if (queue->fd > 2 && close(queue->fd) == -1)
	return (write_error(__FILE__, __func__, __LINE__, -1));
      free(queue->ringbuffer);
      free(queue);
      queue = tmp;
    }
  return (0);
}

int		free_data(t_data *data)
{
  unsigned int	x;
  unsigned int	y;

  if (free_players(data->players_root) == -1 ||
      free_network(data->network) == -1)
    return (84);
  y = -1;
  while (++y < data->height)
    free(data->map[y]);
  free(data->map);
  x = -1;
  while (data->team_list && data->team_list[++x])
    {
      free(data->team_list[x]->name);
      free(data->team_list[x]);
    }
  free(data->team_list);
  free_eggs(data->eggs);
  if (free_queue(data->queue) == -1)
    return (84);
  free(data);
  return (0);
}
