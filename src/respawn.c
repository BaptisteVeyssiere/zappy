/*
** respawn.c for Project-Master in /home/veyssi_b/rendu/tek2/PSU/PSU_2016_zappy
**
** Made by Baptiste Veyssiere
** Login   <veyssi_b@epitech.net>
**
** Started on  Wed Jun 28 15:49:51 2017 Baptiste Veyssiere
** Last update Wed Jun 28 15:53:41 2017 Baptiste Veyssiere
*/

#include <stdlib.h>
#include "server.h"

void	respawn(t_data *data, int type)
{
  int	x;
  int	y;

  x = rand() % data->width;
  y = rand() % data->height;
  ++(data->map[y][x].item[type]);
}
