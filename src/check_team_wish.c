/*
** check_team_wish.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Sun Jun 25 02:09:52 2017 Baptiste Veyssiere
** Last update Mon Jun 26 21:47:57 2017 Baptiste Veyssiere
*/

#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

int	read_socket(int fd, t_ringbuffer *ringbuffer)
{
  int	ret;
  char	buff[READING_SIZE + 1];
  int	i;

  bzero(buff, READING_SIZE + 1);
  ret = read(fd, buff, READING_SIZE);
  if (ret < 1)
    return (-1);
  i = -1;
  while (buff[++i])
    {
      ringbuffer->data[ringbuffer->write_ptr] = buff[i];
      if (++(ringbuffer->write_ptr) == RINGLENGTH)
	ringbuffer->write_ptr = 0;
    }
  return (0);
}

static int	ring_in_buff(char *buff, char *str, int pos)
{
  int		i;

  i = -1;
  while (1)
    {
      if (str[pos] == '\n')
	{
	  str[pos] = 0;
	  return (1);
	}
      buff[++i] = str[pos];
      str[pos] = 0;
      if (++pos == RINGLENGTH)
	pos = 0;
    }
  buff[++i] = 0;
  buff[++i] = 0;
  return (0);
}

static char	*dynamic_cmd(char buff[RINGLENGTH + 1])
{
  char		*ret;
  int		i;

  if (!(ret = malloc(strlen(buff) + 1)))
    return (NULL);
  bzero(ret, strlen(buff) + 1);
  i = -1;
  while (buff[++i])
    ret[i] = buff[i];
  return (ret);
}

char		*check_ring(t_ringbuffer *ringbuffer, char first, int *is_cmd)
{
  static char	buff[RINGLENGTH + 1];
  int		tmp;

  bzero(buff, RINGLENGTH + 1);
  tmp = ringbuffer->read_ptr;
  while ((first == 0 || (ringbuffer->read_ptr != tmp)) &&
	 ringbuffer->data[ringbuffer->read_ptr] != 0)
    {
      first = 1;
      if (ringbuffer->read_ptr == RINGLENGTH)
	ringbuffer->read_ptr = 0;
      if (ringbuffer->data[ringbuffer->read_ptr] == '\n')
	{
	  ++ringbuffer->read_ptr;
	  ring_in_buff(buff, ringbuffer->data, tmp);
	  *is_cmd = 1;
	  return (dynamic_cmd(buff));
	}
      ++ringbuffer->read_ptr;
    }
  ringbuffer->read_ptr = tmp;
  return (NULL);
}

int	check_team_wish(t_data *data, t_waiting_queue *elem)
{
  int	ret;
  int	is_cmd;
  char	*command;

  if ((ret = read_socket(elem->fd, elem->ringbuffer)) == -1)
    {
      FD_CLR(elem->fd, data->network->set);
      return (1);
    }
  is_cmd = 0;
  while ((command = check_ring(elem->ringbuffer, 0, &is_cmd)))
    {
      printf("<%s>\n", command);
      if ((ret = try_add_player(data, elem->fd,
				command, elem->ringbuffer)) == -1)
	return (-1);
      else if (ret == 1)
	{
	  free(elem);
	  return (1);
	}
      free(command);
      is_cmd = 0;
    }
  return (is_cmd != 0 ? -1 : 0);
}
