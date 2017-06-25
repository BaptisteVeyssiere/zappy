/*
** all_structs.h for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/include
**
** Made by Nathalie CAI
** Login   <abel@epitech.eu>
**
** Started on  Wed Jun 21 11:46:52 2017 Nathalie CAI
** Last update Fri Jun 23 18:20:19 2017 Baptiste Veyssiere
*/

#ifndef ALL_STRUCTS_H_
# define ALL_STRUCTS_H_

# include <sys/select.h>

enum	dir
  {
    UP = 0,
    RIGHT,
    DOWN,
    LEFT,
    UNKNOWN
  };

typedef struct		s_team
{
  char			*name;
  int			free_slots;
  unsigned int		highest_level;
}			t_team;

typedef struct		s_position
{
  unsigned int		x;
  unsigned int		y;
}			t_position;

typedef struct		s_action
{
  char			*action;
  int			timer;
  struct s_action	*next;
}			t_action;

typedef struct		s_waiting_queue
{
  char			*team;
  int			fd;
  struct s_waiting_queue *next;
}			t_waiting_queue;

typedef struct		s_egg
{
  int			fd;
  int			timer;
  char			*team;
  t_position		*pos;
  struct s_egg		*next;
}			t_egg;

typedef struct		s_items
{
/*  unsigned int		food;
  unsigned int		linemate;
  unsigned int		deraumere;
  unsigned int		sibur;
  unsigned int		mendiane;
  unsigned int		phiras;
  unsigned int		thystame;*/
  unsigned int		item[ITEMNBR];
  unsigned int		players;
  unsigned int		eggs;
}			t_items;

typedef struct		s_player
{
  t_items		*inventory;
  char			*team;
  int			fd;
  t_position		*pos;
  //unsigned int		sightline;
  enum dir		direction;
  unsigned int		level;
  unsigned int		life;
  t_action		*action;
  struct s_player	*next;
}			t_player;

typedef struct		s_network
{
  int			socket_fd[2];
  fd_set		*set;
  int			graphic_fd;
  int			signal_fd;
}			t_network;

typedef struct		s_data
{
  t_player		*players_root;
  t_network		*network;
  unsigned int		freq;
  unsigned int		width;
  unsigned int		height;
  t_items		**map;
  unsigned int		nbr_teams;
  t_team		**team_list;
  t_egg			*eggs;
  unsigned int		player_limit;
  unsigned int		seed;
  int			port;
}			t_data;

/*
**	Ajout d'un buffer circulaire pour lire commande client ?
**	ajout dans t_data d'une structure s_pollfd ou autre suivant utilisation poll ou select ? (poll plus facile a utilisé)
*/
#endif /* !ALL_STRUCTS_H_ */
