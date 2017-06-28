/*
** broadcast.h for zappy in /home/guilbo_m/rendu/PSU/PSU_2016_zappy
** 
** Made by Mathis Guilbon
** Login   <guilbo_m@epitech.net>
** 
** Started on  Tue Jun 27 19:42:14 2017 Mathis Guilbon
** Last update Tue Jun 27 22:33:04 2017 Mathis Guilbon
*/

#ifndef _BROADCAST_H
#  define _BROADCAST_H

#  include "math.h"

#  define ABS(x)(x > 0 ? x : -x)

enum
  {
    TOP_LEFT = 1,
    TOP_MIDDLE,
    TOP_RIGHT,
    MIDDLE_RIGHT,
    BOTTOM_RIGHT,
    BOTTOM_MIDDLE,
    BOTTOM_LEFT,
    MIDDLE_LEFT,
    CASENBR
  };

#endif /* !_BROADCAST_H */
