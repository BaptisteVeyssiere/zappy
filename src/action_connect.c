/*
** action_connect.c for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Mon Jun 19 19:38:17 2017 Mathis Guilbon
** Last update Mon Jun 26 13:38:28 2017 Mathis Guilbon
*/

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
