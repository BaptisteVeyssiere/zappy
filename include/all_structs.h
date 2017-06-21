/*
** all_structs.h for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/include
** 
** Made by Nathalie CAI
** Login   <abel@epitech.eu>
** 
** Started on  Wed Jun 21 11:46:52 2017 Nathalie CAI
** Last update Wed Jun 21 12:22:50 2017 Mathis Guilbon
*/

#ifndef ALL_STRUCTS_H_
# define ALL_STRUCTS_H_

enum	dir
  {
    UP,
    DOWN,
    LEFT,
    RIGHT
  };

typedef struct		s_team
{
  char			*name;
  int			free_slot;
  unsigned int		higher_lvl;// evite de parser players et team, pour savoir qui gagne
}			t_team;

typedef struct		s_position
{
  unsigned int		x;
  unsigned int		y;
}			t_position;

typedef struct		s_action
{
  char			*action;
  unsigned int		start;
  unsigned int		interval;
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
  unsigned int		time;
  char			*team;
  t_position		*pos;
  struct s_egg		*next;
}			t_egg;

typedef struct		s_items
{
  unsigned int		food;
  unsigned int		linemate;
  unsigned int		deraumere;
  unsigned int		sibur;
  unsigned int		mendiane;
  unsigned int		phiras;
  unsigned int		thystame;
}			t_items;

typedef struct		s_player
{
  t_items		*inventory;
  char			*team;
  int			fd;
  t_position		*pos;
  unsigned int		sightline;
  enum dir		direction;
  unsigned int		level;
  unsigned int		life;
  t_action		*action;
  struct s_player	*next;
}			t_player;
/*
**	contient tableau de t_player et t_egg
*/
typedef struct		s_case
{
  t_player		**player;
  t_egg			**egg;
  t_item		*item;
}			t_case;

typedef struct		s_data
{
  t_player		*players_root;
  unsigned int		freq;
  unsigned int		width;
  unsigned int		height;
  t_case		*map;
  t_items		*total;// l'integralité des ressources de la map, respawn de ressource si trop bas ?
  //  t_items		**map   il peut y avoir plusieur chose sur une case de la map;
  t_team		*team_list;
  //t_team		**team_list  ptr sur debut de list suffit ?;
  t_egg			*eggs;
  unsigned int		player_limit;
}			t_data;

/*
**	Ajout d'un buffer circulaire pour lire commande client ?
**	ajout dans t_data d'une structure s_pollfd ou autre suivant utilisation poll ou select ? (poll plus facile a utilisé)
*/
#endif /* !ALL_STRUCTS_H_ */
