//
// Created by root on 25/06/17.
//

bool		action_connect_nbr(t_data *data, t_player *player, char *prm)
{
  char 		buff[8];
  int		i;

  (void)prm;
  i = -1;
  while (++i < data->nbr_teams &&
	 strcmp(data->team_list[i]->name, player->team) != 0);
  if (i < data->nbr_teams)
    {
      snprintf(buff, 8, data->team_list[i]->free_slots);
      socket_write(player->fd, buff);
    }
  return (true);
}

bool		action_fork(t_data *data, t_player *player, char *prm)
{
  return (true);
}

bool		action_broadcast(t_data *data, t_player *player, char *prm)
{
  return (true);
}