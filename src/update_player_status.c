/*
** update_player_status.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Mon Jun 26 20:24:46 2017 Baptiste Veyssiere
** Last update Wed Jun 28 17:27:44 2017 Baptiste Veyssiere
*/

#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

static int	free_player(t_player *player, t_data *data)
{
  t_action	*action;
  t_action	*tmp;

  free(player->inventory);
  free(player->team);
  free(player->pos);
  free(player->ringbuffer);
  action = player->action;
  while (action)
    {
      tmp = action->next;
      free(action->action);
      free(action);
      action = tmp;
    }
  FD_CLR(player->fd, data->network->set);
  if (player->fd > 2 && close(player->fd) == -1)
    return (write_error(__FILE__, __func__, __LINE__, -1));
  free(player);
  return (0);
}

static void	add_slot_for_team(t_data *data, t_player *player)
{
  int		i;

  i = -1;
  if (player->eggborn)
    return ;
  while (data->team_list[++i])
    {
      if (strcmp(player->team, data->team_list[i]->name) == 0)
	{
	  ++(data->team_list[i]->free_slots);
	  return ;
	}
    }
}

static int	player_death(t_player *player, t_data *data)
{
  t_player	*elem;
  t_player	*prev;
  t_player	*tmp;

  prev = NULL;
  elem = data->players_root;
  if (socket_write(player->fd, "dead\n") == -1)
    return (-1);
  --(data->map[player->pos->y][player->pos->x].players);
  add_slot_for_team(data, player);
  while (elem)
    {
      tmp = elem->next;
      if (elem == player)
	{
	  if (free_player(elem, data) == -1)
	    return (-1);
	  if (prev == NULL)
	    data->players_root = tmp;
	  else
	    prev->next = tmp;
	  return (0);
	}
      prev = elem;
      elem = tmp;
    }
  return (0);
}

int	update_player_status(t_data *data)
{
  struct timeval	tv;
  t_player		*tmp;
  unsigned int		current_time;

  tmp = data->players_root;
  gettimeofday(&tv, NULL);
  current_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
  while (tmp)
    {
      if (tmp->life < current_time)
	{
	  if (tmp->inventory->item[FOOD] == 0)
	    return (player_death(tmp, data));
	  tmp->inventory->item[FOOD] -= 1;
	  tmp->life = current_time + (126.0 / data->freq) * 1000;
	}
      tmp = tmp->next;
    }
  return (0);
}
