/*
** init_map.c for Project-Master in /home/nathalie/rendu/network/PSU_2016_zappy/src
** 
** Made by Nathalie CAI
** Login   <nathalie.cai@epitech.eu>
** 
** Started on  Mon Jun 26 16:47:55 2017 Nathalie CAI
** Last update Tue Jun 27 11:42:16 2017 Nathalie CAI
*/

#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include "server.h"

static t_data	*filling_loop(t_data *data,
			      unsigned int max_rocks[ITEMNBR], int i)
{
  unsigned int	j;
  unsigned int	k;

  j = 0;
  while (j < data->width)
    {
      k = 0;
      while (k < ITEMNBR)
	{
	  if (rand() % 2 == 0 && k == 0 && max_rocks[k] > 0)
		{
		  data->map[i][j].item[k] = rand() % 5;
		  max_rocks[k] = max_rocks[k] - data->map[i][j].item[k];
		}
	  if (rand() % 2 == 0 && k > 0 && max_rocks[k] > 0)
	    {
	      data->map[i][j].item[k] = rand() % 2;
	      max_rocks[k] = max_rocks[k] - data->map[i][j].item[k];
	    }
	  k++;
	}
      j++;
    }
  return (data);
}

static t_data	*fill_tile(t_data *data)
{
  unsigned int	max_rocks[ITEMNBR];
  unsigned int	i;

  i = 0;
  while (i < ITEMNBR)
    {
      if (i == 0)
	max_rocks[i] = (data->width * data->height) * 3;
      else
	max_rocks[i] = (data->width * data->height) / 3 * 2;
      i++;
    }
  srand(data->seed);
  i = 0;
  while (i < data->height)
    {
      data = filling_loop(data, max_rocks, i);
      i++;
    }
  return (data);
}

t_data	*init_map(t_data *data)
{
  unsigned int  i;

  if ((data->map = malloc(sizeof (t_items *) * data->height)) == NULL)
    return (NULL);
  bzero(data->map, sizeof (t_items*));
  i = 0;
  while (i < data->height)
    {
      if ((data->map[i] = malloc(sizeof (t_items) * data->width)) == NULL)
	return (NULL);
      bzero(data->map[i], sizeof (t_items));
      i++;
    }
  data = fill_tile(data);
  return (data);
}
