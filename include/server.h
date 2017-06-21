/*
** server.h for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 21 00:50:35 2017 Baptiste Veyssiere
** Last update Wed Jun 21 16:43:56 2017 Nathalie CAI
*/

#ifndef __SERVER_H__
# define __SERVER_H__

# include "all_structs.h"

# define MSG_LEN 512
# define QUEUE_SIZE 42

/*
** write_error.c
*/

int	write_error(const char *file, const char *func,
		    const int line, const int ret);

/*
** init_server.c
*/

int	bind_port(const int port);

/*                                                                                                                   
** get_args.c                                                                                                        
*/

unsigned int    get_port(int, char **);
unsigned int    get_width(int, char **);
unsigned int    get_height(int, char **);
unsigned int    get_freq(int, char **);
unsigned int    get_client_max(int, char **);

/*
** init_data.c
*/

t_data  *init_data(t_data *data, int ac, char **av);

/*
** init_data.c
*/

void    print_data(t_data *data);

#endif /* !__SERVER_H__ */
