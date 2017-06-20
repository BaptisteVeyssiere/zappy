/*
** server.h for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 21 00:50:35 2017 Baptiste Veyssiere
** Last update Wed Jun 21 01:05:03 2017 Baptiste Veyssiere
*/

#ifndef __SERVER_H__
# define __SERVER_H__

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

#endif /* !__SERVER_H__ */
