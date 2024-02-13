/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_defines.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:31:22 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/13 12:18:47 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEFINES_H
# define SO_LONG_DEFINES_H

/// BONUS
# ifndef BONUS
#  define BONUS 0
# endif

/// COORDINATES
# define X 0
# define Y 1

/// SIZES
# define WIDTH 1920
# define HEIGHT 1200
# define MAX_HEIGHT 32
# define MAX_WIDTH 60

/// MAP CHAR
# define SPACE '0'
# define WALL '1'
# define COIN 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMIES 'X'

/// ERROR MESSAGES
# define INVALID_MAP "Invalid map: maybe stop putting random things in it?\n"
# define OVERSIZE_MAP "Map way too big bro, way too big\n"
# define MALLOC_ERR "Failed to malloc data"

#endif