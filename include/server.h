/*
** server.h for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 21 00:50:35 2017 Baptiste Veyssiere
** Last update Sun Jun 25 05:01:13 2017 Baptiste Veyssiere
*/

#ifndef SERVER_H_
# define SERVER_H_

# include "all_structs.h"

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

/*
** add_player.c
*/

int	try_add_player(t_data *data, int fd, char *team, t_ringbuffer *ringbuffer);

#endif /* !SERVER_H_ */
