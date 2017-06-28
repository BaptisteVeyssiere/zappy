/*
** incantation.h for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Tue Jun 27 13:00:40 2017 Mathis Guilbon
** Last update Wed Jun 28 13:58:49 2017 Mathis Guilbon
*/

#ifndef _INCANTATION_H_
#  define _INCANTATION_H_

#  include "server.h"

static	bool	(*incant[7])(t_data *, t_player *) =
{
  upgrade_to_lvl2,
  upgrade_to_lvl3,
  upgrade_to_lvl4,
  upgrade_to_lvl5,
  upgrade_to_lvl6,
  upgrade_to_lvl7,
  upgrade_to_lvl8
};

#endif /* !_INCANTATION_H_ */
