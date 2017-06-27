/*
** incantation.h for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Tue Jun 27 13:00:40 2017 Mathis Guilbon
** Last update Tue Jun 27 13:17:47 2017 Mathis Guilbon
*/

#ifndef _INCANTATION_H_
#  define _INCANTATION_H_

#  include "server.h"

static	bool	(*incant[7])(t_data *, t_player *) =
{
  upgradeToLvl2,
  upgradeToLvl3,
  upgradeToLvl4,
  upgradeToLvl5,
  upgradeToLvl6,
  upgradeToLvl7,
  upgradeToLvl8
};

#endif /* !_INCANTATION_H_ */
