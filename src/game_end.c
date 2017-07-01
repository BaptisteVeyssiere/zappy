/*
** game_end.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zap
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Thu Jun 29 15:09:56 2017 Baptiste Veyssiere
** Last update Sat Jul  1 15:07:46 2017 Baptiste Veyssiere
*/

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include "server.h"

static int	seg(t_data *data, char *team)
{
  char		buff[100];

  if (data->network->graphic_fd == -1)
    return (0);
  bzero(buff, 100);
  if (snprintf(buff, 100, "seg %s\n", team) < 0 ||
      socket_write(data->network->graphic_fd, buff) == -1)
    return (-1);
  return (0);
}

static int	ending(t_data *data, char *team)
{
  char		buff[500];

  bzero(buff, 500);
  if (snprintf(buff, 500, "Team %s wins\n", team) < 0 ||
      socket_write(1, buff) == -1 ||
      seg(data, team) == -1)
    return (-1);
  return (1);
}

int		game_end(t_data *data)
{
  int		max_players;
  t_player	*tmp;
  int		i;

  i = -1;
  if (!(data->team_list))
    return (0);
  while (data->team_list[++i])
    {
      tmp = data->players_root;
      max_players = 0;
      while (tmp)
	{
	  if (strcmp(data->team_list[i]->name, tmp->team) == 0 &&
	      tmp->level == 8)
	    ++max_players;
	  tmp = tmp->next;
	}
      if (max_players >= 6)
	return (ending(data, data->team_list[i]->name));
    }
  return (0);
}
