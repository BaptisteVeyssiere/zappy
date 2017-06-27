/*
** server.h for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 21 00:50:35 2017 Baptiste Veyssiere
** Last update Tue Jun 27 13:20:48 2017 Mathis Guilbon
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "all_structs.h"
# include <string.h>
# include <stdbool.h>
# include <stdio.h>

# define MSG_LEN 512
# define QUEUE_SIZE 42
# define GRAPHIC_PORT 50000
# define READING_SIZE 256
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
** init_data.c
*/

t_data  *init_data(t_data *data, int ac, char **av);

/*
** init_data.c
*/

void    print_data(t_data *data);

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

int	check_sockets(t_data *data);

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
** update_egg_status.c
*/

void	update_egg_status(t_data *data);

/*
** send_basic_info.c
*/

int	send_basic_info(int fd, int free_slot, int width, int height);

/*
**	action_connect.c
*/

bool		eject(t_data *, t_player *, t_position *, char *);
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

void		getRealPosFrom(t_data *, t_position *);
bool		action_forward(t_data *, t_player *, char *);
bool		action_right(t_data *, t_player *, char *);
bool		action_left(t_data *, t_player *, char *);
bool		action_eject(t_data *, t_player *, char *);

/*
**	incantation.c
*/

void		upgrade_player(t_data *, t_player *);
bool		enoughPeople(t_data *, t_player *, unsigned int);
bool		upgradeToLvl2(t_data *, t_player *);
bool		upgradeToLvl3(t_data *, t_player *);
bool		upgradeToLvl4(t_data *, t_player *);

/*
**	incantation2.c
*/

bool		upgradeToLvl5(t_data *, t_player *);
bool		upgradeToLvl6(t_data *, t_player *);
bool		upgradeToLvl7(t_data *, t_player *);
bool		upgradeToLvl8(t_data *, t_player *);

/*
**	action_look.c
*/

int		power(int, int);
bool		checkOverflow(int *, char *, int);
bool		lookOneCase(t_items *, int *, char *, int);
void		changeOffset(enum dir, t_position *, int *, int);
bool		action_look(t_data *, t_player *, char *);

#endif /* !SERVER_H_ */
