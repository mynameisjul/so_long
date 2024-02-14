/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_defines.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:31:22 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/14 16:29:42 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEFINES_H
# define SO_LONG_DEFINES_H

/// BONUS
# ifndef BONUS
#  define BONUS 0
# endif

/// NAME
# define NAME "Poney poney run run"

/// COORDINATES
# define X 0
# define Y 1

/// SIZES
# define WIDTH 1920
# define HEIGHT 1200
# define MAX_HEIGHT 32
# define MAX_WIDTH 60
# define TILE 32

/// MAP CHAR
# define SPACE '0'
# define WALL '1'
# define COIN 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMIES 'X'

/// MAP TILES
# define T_SPACE "./assets/space.xpm"
# define T_TL "./assets/top_left.xpm"
# define T_TR "./assets/top_right.xpm"
# define T_BL "./assets/bott_left.xpm"
# define T_BR "./assets/bott_right.xpm"
# define T_TOP "./assets/top.xpm"
# define T_BOTT "./assets/bott.xpm"
# define T_LEFT "./assets/left.xpm"
# define T_RIGHT "./assets/right.xpm"
# define T_COIN "./assets/coin.xpm"
# define T_COLLEC_COIN "./assets/collected_coin.xpm"
# define T_WALL "./assets/obstacle.xpm"
# define T_EXIT "./assets/closed_exit.xpm"
# define T_OPEN_EXIT "./assets/open_exit.xpm"
# define T_PLAYER_COIN "./assets/player_on_coin.xpm"
# define T_PLAYER "./assets/player.xpm"

/// ERROR MESSAGES
# define INVALID_MAP "Invalid map: maybe stop putting random things in it?\n"
# define OVERSIZE_MAP "Oversize: Map way too big bro, way too big\n"
# define MALLOC_ERR "Malloc error: Failed to malloc data\n"
# define NO_PATH "No solution path: No way you're getting out with all the coins\n"
# define WINDOW "Failed to open a window\n"
# define LOAD_ASSETS "Assets error: could not load the game's spleeeeeendid assets\n"

#endif