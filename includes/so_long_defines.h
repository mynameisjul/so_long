/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_defines.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:31:22 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/19 13:16:30 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEFINES_H
# define SO_LONG_DEFINES_H

/// BONUS
# ifndef BONUS
#  define BONUS 0
#endif

/// NAME
# define NAME "Poney poney run run"

/// COORDINATES
# define X 0
# define Y 1

/// SIZES
# define WIDTH 1920
# define HEIGHT 1200
# define MAX_HEIGHT 36
# define MAX_WIDTH 60
# define TILE 32
# define LEVEL_SIZE 15

/// MAP CHAR
# define SPACE '0'
# define WALL '1'
# define COIN 'C'
# define EXIT 'E'
# define OPEN_EXIT 'e'
# define COL_COIN 'c'
# define PLAY_ON_COIN 'p'
# define LPLAYER 'Q'
# define LPLAY_ON_COIN 'q'
# define PLAY_ON_CCOIN 'R'
# define LPLAY_ON_CCOIN 'r'
# define PLAYER 'P'
# define ENEMIES 'X'
# define LENEMIES 'x'
# define DEAD 'D'

/// MAP TILES
# define NB_ASSETS 25
# define T_SPACE 0
# define T_TL 1
# define T_TR 2
# define T_BL 3
# define T_BR 4
# define T_TOP 5
# define T_BOTT 6
# define T_LEFT 7
# define T_RIGHT 8
# define T_COIN 9
# define T_COLLEC_COIN 10
# define T_WALL 11
# define T_EXIT 12
# define T_OPEN_EXIT 13
# define T_PLAYER_COIN 14
# define T_PLAYER 15
# define T_P1 16
# define T_P2 17
# define T_P3 18
# define T_P4 15
# define T_ENEMY 19
# define T_LP1 20
# define T_LP2 21
# define T_LP3 22
# define T_LP4 23
# define T_LPLAYER_COIN 24
# define T_LPLAYER 23
# define T_LOWERBORDER 25

/// PLAYER MOVES
# define ESCAPE 65307
# define UP 'w'
# define LEFT 'a'
# define DOWN 's'
# define RIGHT 'd'

/// END
# define RUN 1
# define LOSE 0
# define WIN 2

/// LOOP
# define SPEED 100

/// ERROR MESSAGES
# define INVALID_MAP "Invalid map: maybe stop putting random things in it?\n"
# define OVERSIZE_MAP "Oversize: Map way too big bro, way too big\n"
# define MALLOC_ERR "Malloc error: Failed to malloc data\n"
# define NO_PATH "No solution path: No way you're getting out with all the coins\n"
# define WINDOW "Failed to open a window\n"
# define LOAD_ASSETS "Assets error: could not load the game's spleeeeeendid assets\n"

#endif