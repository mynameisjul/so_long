/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_movements_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:18:25 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/20 14:37:19 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_single_enemy_up(t_data *data, int x, int y)
{
	if (data->map.map_data[y - 1][x] == WALL
		|| data->map.map_data[y - 1][x] == COIN
		|| data->map.map_data[y - 1][x] == COL_COIN
		|| data->map.map_data[y - 1][x] == OPEN_EXIT
		|| data->map.map_data[y - 1][x] == EXIT
		|| data->map.map_data[y - 1][x] == ENEMIES
		|| data->map.map_data[y - 1][x] == LENEMIES)
		return (RUN);
	if (data->map.map_data[y - 1][x] == SPACE)
	{
		if (data->map.map_data[y][x] == ENEMIES)
			data->map.map_data[y - 1][x] = ENEMIES;
		if (data->map.map_data[y][x] == LENEMIES)
			data->map.map_data[y - 1][x] = LENEMIES;
		data->map.map_data[y][x] = SPACE;
		return (WIN);
	}
	if (data->map.map_data[y - 1][x] == PLAY_ON_CCOIN
		|| data->map.map_data[y - 1][x] == PLAY_ON_COIN
		|| data->map.map_data[y - 1][x] == PLAYER
		|| data->map.map_data[y - 1][x] == LPLAY_ON_CCOIN
		|| data->map.map_data[y - 1][x] == LPLAY_ON_COIN
		|| data->map.map_data[y - 1][x] == LPLAYER)
		return (LOSE);
	return (0);
}

int	move_single_enemy_down(t_data *data, int x, int y)
{
	if (data->map.map_data[y + 1][x] == WALL
		|| data->map.map_data[y + 1][x] == COIN
		|| data->map.map_data[y + 1][x] == COL_COIN
		|| data->map.map_data[y + 1][x] == OPEN_EXIT
		|| data->map.map_data[y + 1][x] == EXIT
		|| data->map.map_data[y + 1][x] == ENEMIES
		|| data->map.map_data[y + 1][x] == LENEMIES)
		return (RUN);
	if (data->map.map_data[y + 1][x] == SPACE)
	{
		if (data->map.map_data[y][x] == ENEMIES)
			data->map.map_data[y + 1][x] = ENEMIES;
		if (data->map.map_data[y][x] == LENEMIES)
			data->map.map_data[y + 1][x] = LENEMIES;
		data->map.map_data[y][x] = SPACE;
		return (RUN);
	}
	if (data->map.map_data[y + 1][x] == PLAY_ON_CCOIN
		|| data->map.map_data[y + 1][x] == PLAY_ON_COIN
		|| data->map.map_data[y + 1][x] == PLAYER
		|| data->map.map_data[y + 1][x] == LPLAY_ON_CCOIN
		|| data->map.map_data[y + 1][x] == LPLAY_ON_COIN
		|| data->map.map_data[y + 1][x] == LPLAYER)
		return (LOSE);
	return (0);
}

int	move_single_enemy_left(t_data *data, int x, int y)
{
	if (data->map.map_data[y][x - 1] == WALL
		|| data->map.map_data[y][x - 1] == COIN
		|| data->map.map_data[y][x - 1] == COL_COIN
		|| data->map.map_data[y][x - 1] == OPEN_EXIT
		|| data->map.map_data[y][x - 1] == EXIT
		|| data->map.map_data[y][x - 1] == ENEMIES
		|| data->map.map_data[y][x - 1] == LENEMIES)
		return (RUN);
	if (data->map.map_data[y][x - 1] == SPACE)
	{
		data->map.map_data[y][x - 1] = LENEMIES;
		data->map.map_data[y][x] = SPACE;
		return (RUN);
	}
	if (data->map.map_data[y][x - 1] == PLAY_ON_CCOIN
		|| data->map.map_data[y][x - 1] == PLAY_ON_COIN
		|| data->map.map_data[y][x - 1] == PLAYER
		|| data->map.map_data[y][x - 1] == LPLAY_ON_CCOIN
		|| data->map.map_data[y][x - 1] == LPLAY_ON_COIN
		|| data->map.map_data[y][x - 1] == LPLAYER)
		return (LOSE);
	return (0);
}

int	move_single_enemy_right(t_data *data, int x, int y)
{
	if (data->map.map_data[y][x + 1] == WALL
		|| data->map.map_data[y][x + 1] == COIN
		|| data->map.map_data[y][x + 1] == COL_COIN
		|| data->map.map_data[y][x + 1] == OPEN_EXIT
		|| data->map.map_data[y][x + 1] == EXIT
		|| data->map.map_data[y][x + 1] == ENEMIES
		|| data->map.map_data[y][x + 1] == LENEMIES)
		return (RUN);
	if (data->map.map_data[y][x + 1] == SPACE)
	{
		data->map.map_data[y][x + 1] = ENEMIES;
		data->map.map_data[y][x] = SPACE;
		return (RUN);
	}
	if (data->map.map_data[y][x + 1] == PLAY_ON_CCOIN
		|| data->map.map_data[y][x + 1] == PLAY_ON_COIN
		|| data->map.map_data[y][x + 1] == PLAYER
		|| data->map.map_data[y][x + 1] == LPLAY_ON_CCOIN
		|| data->map.map_data[y][x + 1] == LPLAY_ON_COIN
		|| data->map.map_data[y][x + 1] == LPLAYER)
		return (LOSE);
	return (0);
}
