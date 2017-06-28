/*
** all_structs.h for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/include
**
** Made by Nathalie CAI
** Login   <abel@epitech.eu>
**
** Started on  Wed Jun 21 11:46:52 2017 Nathalie CAI
** Last update Mon Jun 26 16:58:31 2017 Baptiste Veyssiere
*/

#ifndef ALL_STRUCTS_H_
# define ALL_STRUCTS_H_

# include <sys/select.h>

# define RINGLENGTH 4096

enum	dir
  {
    UP = 0,
    RIGHT,
    DOWN,
    LEFT,
    UNKNOWN
  };

enum {
  FOOD,
  SIBUR,
  PHIRAS,
  LINEMATE,
  MENDIANE,
  THYSTAME,
  DERAUMERE,
  ITEMNBR
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
  char			ready;
  struct s_action	*next;
}			t_action;

typedef struct		s_ringbuffer
{
  char			data[RINGLENGTH];
  int			write_ptr;
  int			read_ptr;
}			t_ringbuffer;

typedef struct		s_waiting_queue
{
  int			fd;
  struct s_waiting_queue *next;
  t_ringbuffer		*ringbuffer;
}			t_waiting_queue;

typedef struct		s_egg
{
  int			timer;
  int			id;
  int			player_id;
  char			*team;
  t_position		*pos;
  char			ready;
  struct s_egg		*next;
}			t_egg;

typedef struct		s_items
{
  unsigned int		item[ITEMNBR];
  unsigned int		players;
}			t_items;

typedef struct		s_player
{
  t_items		*inventory;
  char			*team;
  int			fd;
  t_position		*pos;
  enum dir		direction;
  unsigned int		level;
  unsigned int		life;
  char			eggborn;
  int			id;
  t_action		*action;
  struct s_player	*next;
  t_ringbuffer		*ringbuffer;
}			t_player;

typedef struct		s_network
{
  int			socket_fd[2];
  fd_set		*set;
  int			graphic_fd;
  int			signal_fd;
  char			graphic_ready;
  t_ringbuffer		*graphic_buffer;
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
  t_waiting_queue	*queue;
  int			port;
  int			pid;
  int			eid;
}			t_data;

#endif /* !ALL_STRUCTS_H_ */