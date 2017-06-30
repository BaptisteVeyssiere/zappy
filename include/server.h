/*
** server.h for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 21 00:50:35 2017 Baptiste Veyssiere
** Last update Fri Jun 30 15:27:21 2017 Baptiste Veyssiere
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "all_structs.h"

# define MSG_LEN 512
# define QUEUE_SIZE 42
# define GRAPHIC_PORT 50000
# define READING_SIZE 256
# define ACTION_NBR 12
# define UNUSED __attribute__((unused))
# define SIGNAL_CAUGHT "Signal caught, closing session...\n"

/*
** writes.c
*/

int	write_error(const char *file, const char *func,
		    const int line, const int ret);
int	socket_write(int fd, char *str);

/*
** init_server.c
*/

int	bind_port(const int port);

/*
** get_args.c
*/

unsigned int    get_uint(int, char **, char *);

/*
** get_args.c
*/

int     check_args(int ac, char **av);

/*
** init_data.c
*/

t_data  *init_data(t_data *data, int ac, char **av);

/*
** make_team_tab.c
*/

char     **team_tab(int ac, char **av);

/*
** init_team_list.c
*/

t_data  *init_team_list(t_data *data, int ac, char **av);

/*
** init_map.c
*/

t_data   *init_map(t_data *data);

/*
** prints.c
*/

int     print_error_param(char *msg);
int	print_usage(void);
void    print_map(t_data *data);
void    print_map_ressources(t_data *data);
void    print_data(t_data *data);
void	print_surrounding_case(t_player *, char *, t_position *, t_position *);

/*
** signal_manager.c
*/

int	check_signal(int fd);
int	create_signal_fd(void);

/*
** main_loop.c
*/

int	main_loop(t_data *data);

/*
** check_sockets.c
*/

int		check_sockets(t_data *data);
t_ringbuffer	*init_ringbuffer(void);

/*
** get_args.c
*/

unsigned int	get_uint(int ac, char **av, char *target);

/*
** free_data.c
*/

int	free_data(t_data *data);

/*
** check_team_wish.c
*/

int	check_team_wish(t_data *data, t_waiting_queue *elem);
char	*check_ring(t_ringbuffer *ringbuffer, char first, int *is_cmd);
int	read_socket(int fd, t_ringbuffer *ringbuffer);

/*
** add_player.c
*/

int	try_add_player(t_data *data, int fd, char *team, t_ringbuffer *ringbuffer);

/*
** update_player_action.c
*/

int	update_player_action(t_data *data, fd_set *set);

/*
** free_tools.c
*/

void	free_actions(t_action *action);

/*
** update_status.c
*/

int	update_egg_status(t_data *data);
void	update_action_status(t_data *data);

/*
** send_basic_info.c
*/

int	send_basic_info(int fd, int free_slot, int width, int height);

/*
**	action_connect.c
*/

void		get_real_pos_from(t_data *, t_position *);
bool		action_connect_nbr(t_data *, t_player *, char *);
bool		action_fork(t_data *, t_player *, char *);
bool		action_broadcast(t_data *, t_player *, char *);

/*
**	action_item.c
*/

bool		action_take(t_data *, t_player *, char *);
bool		action_set(t_data *, t_player *, char *);
bool		action_inventory(t_data *, t_player *, char *);
bool		action_incantation(t_data *, t_player *, char *);

/*
**	action_move.c
*/

bool		action_forward(t_data *, t_player *, char *);
bool		action_right(t_data *, t_player *, char *);
bool		action_left(t_data *, t_player *, char *);
bool		action_eject(t_data *, t_player *, char *);

/*
**	incantation.c
*/

void		upgrade_player(t_data *, t_player *);
bool		enough_people(t_data *, t_player *, unsigned int);
bool		upgrade_to_lvl2(t_data *, t_player *);
bool		upgrade_to_lvl3(t_data *, t_player *);
bool		upgrade_to_lvl4(t_data *, t_player *);

/*
**	incantation2.c
*/

bool		upgrade_to_lvl5(t_data *, t_player *);
bool		upgrade_to_lvl6(t_data *, t_player *);
bool		upgrade_to_lvl7(t_data *, t_player *);
bool		upgrade_to_lvl8(t_data *, t_player *);

/*
**	action_look.c
*/

bool		action_look(t_data *, t_player *, char *);

/*
**	action_broadcast.c
*/

bool		action_broadcast(t_data *, t_player *, char *);

/*
** init_graphic.c
*/

int	init_graphic(t_data *data);
int	get_graphic_info(t_data *data);

/*
** graphic_init_cmd.c
*/

int	init_pnw(t_data *data);
int	init_enw(t_data *data);

/*
** graphic_command.c
*/

int	msz(t_data *data);
int	sgt(t_data *data);
int	bct(t_data *data);
int	tna(t_data *data);
int	pdi(t_data *data, t_player *player);

/*
** update_player_status.c
*/

int	update_player_status(t_data *data);
void	add_slot_for_team(t_data *data, t_player *player);

/*
** execute_actions.c
*/

void	set_action_timer(t_action *action, int duration, unsigned int freq);
int	execute_actions(t_data *data);

/*
** get_command_duration.c
*/

int	get_command_duration(char *command);

/*
** respawn.c
*/

void	respawn(t_data *data, int type);

/*
** graphic_moves.c
*/

int	ppo(t_player *player, t_data *data);
int	pnw(t_player *player, t_data *data);

/*
** graphic_egg.c
*/

int	eht(t_data *data, t_egg *egg);
int	enw(t_data *data, t_egg *egg);
int	ebo(t_data *data, t_egg *egg);

/*
** game_end.c
*/

int	game_end(t_data *data);

/*
** graphic_actions.c
*/

int	graphic_take(t_data *data, t_player *player, int type);
int	graphic_put(t_data *data, t_player *player, int type);

/*
** graphic_cmd.c
*/

int	pex(t_data *data, t_player *player);
int	pie(t_data *data, unsigned int x, unsigned int y, int result);
int	plv(t_data *data, t_player *player);
int	pbc(t_data *data, t_player *player, char *message);

/*
** graphic_incantation.c
*/

int	pic_init(t_data *data, t_player *player);
int	pic(t_data *data, t_player *player);
int	pic_end(t_data *data);

#endif /* !SERVER_H_ */
