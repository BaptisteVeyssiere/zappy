/*
** all_structs.h for Project-Master in /home/nathalie/rendu/network/PSU_2016_
**
** Made by Nathalie CAI
** Login   <abel@epitech.eu>
**
** Started on  Wed Jun 21 11:46:52 2017 Nathalie CAI
** Last update Sun Jul  2 15:22:56 2017 Baptiste Veyssiere
*/

#ifndef ALL_STRUCTS_H_
# define ALL_STRUCTS_H_

# include <sys/select.h>
# include <stdbool.h>

# define RINGLENGTH 4096

enum	dir
  {
    UP = 1,
    RIGHT,
    DOWN,
    LEFT,
    UNKNOWN
  };

enum
  {
    FOOD = 0,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    ITEMNBR
  };

enum
  {
    TOP_MIDDLE = 1,
    TOP_LEFT,
    MIDDLE_LEFT,
    BOTTOM_LEFT,
    BOTTOM_MIDDLE,
    BOTTOM_RIGHT,
    MIDDLE_RIGHT,
    TOP_RIGHT,
    CASENBR
  };

typedef struct		s_team
{
  char			*name;
  int			free_slots;
  unsigned int		highest_level;
}			t_team;

typedef struct		s_position
{
  int			x;
  int			y;
}			t_position;

typedef struct		s_point
{
  float			x;
  float			y;
}			t_point;

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
  unsigned long int	timer;
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

typedef struct		s_network
{
  int			socket_fd[2];
  fd_set		*set;
  int			graphic_fd;
  int			signal_fd;
  char			graphic_ready;
  t_ringbuffer		*graphic_buffer;
}			t_network;

typedef struct		s_action
{
  char			*action;
  unsigned long int	timer;
  char			ready;
  char			incant_checked;
  struct s_action	*next;
  struct s_incantation	*list;
}			t_action;

typedef struct		s_player
{
  t_items		*inventory;
  char			*team;
  int			fd;
  t_position		*pos;
  enum dir		direction;
  unsigned int		level;
  unsigned long int	life;
  char			eggborn;
  int			id;
  t_action		*action;
  struct s_player	*next;
  struct s_player	*inext;
  t_ringbuffer		*ringbuffer;
}			t_player;

typedef struct		s_incantation
{
  t_player		**player;
  struct s_incantation	*next;
}			t_incantation;

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

typedef struct  s_act
{
  char          *name;
  bool          (*func)(t_data *, t_player *, char *);
  unsigned int  duration;
}               t_act;

#endif /* !ALL_STRUCTS_H_ */
