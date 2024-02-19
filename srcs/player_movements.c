/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:33:54 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/19 10:34:09 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int player_up(t_data *data)
{
	int x;
	int y;

	x = data->map.player[Y] - 1;
	y = data->map.player[X];
	if (x == 0 || data->map.map_data[x][y] == WALL || data->map.map_data[x][y] == EXIT)
		return (RUN);
	if (data->map.map_data[x][y] == ENEMIES)
		return (LOSE);
	if (data->map.map_data[x][y] == OPEN_EXIT)
		return (WIN);
	if (data->map.map_data[x + 1][y] == LPLAYER || data->map.map_data[x + 1][y] == LPLAY_ON_CCOIN || data->map.map_data[x + 1][y] == LPLAY_ON_COIN)
		left_player_update(data, x, y);
	if (data->map.map_data[x + 1][y] == PLAYER || data->map.map_data[x + 1][y] == PLAY_ON_CCOIN || data->map.map_data[x + 1][y] == PLAY_ON_COIN)
		right_player_update(data, x, y);
	data->map.player[Y]--;
	whole_map_update(data, x + 1, y);
	return (RUN);
}

int player_down(t_data *data)
{
	int x;
	int y;

	x = data->map.player[Y] + 1;
	y = data->map.player[X];
	if (x == data->map.size[Y] - 1 || data->map.map_data[x][y] == WALL || data->map.map_data[x][y] == EXIT)
		return (RUN);
	if (data->map.map_data[x][y] == ENEMIES)
		return (LOSE);
	if (data->map.map_data[x][y] == OPEN_EXIT)
		return (WIN);
	if (data->map.map_data[x - 1][y] == LPLAYER || data->map.map_data[x - 1][y] == LPLAY_ON_CCOIN || data->map.map_data[x - 1][y] == LPLAY_ON_COIN)
		left_player_update(data, x, y);
	if (data->map.map_data[x - 1][y] == PLAYER || data->map.map_data[x - 1][y] == PLAY_ON_CCOIN || data->map.map_data[x - 1][y] == PLAY_ON_COIN)
		right_player_update(data, x, y);
	data->map.player[Y]++;
	whole_map_update(data, x - 1, y);
	return (RUN);
}

int player_left(t_data *data)
{
	int x;
	int y;

	x = data->map.player[Y];
	y = data->map.player[X] - 1;
	if (y == 0 || data->map.map_data[x][y] == WALL || data->map.map_data[x][y] == EXIT)
	{
		data->map.map_data[x][y + 1] = LPLAYER;
		return (RUN);
	}
	if (data->map.map_data[x][y] == ENEMIES)
		return (LOSE);
	if (data->map.map_data[x][y] == OPEN_EXIT)
		return (WIN);
	left_player_update(data, x, y);
	data->map.player[X]--;
	whole_map_update(data, x, y + 1);
	return (RUN);
}

int player_right(t_data *data)
{
	int x;
	int y;

	x = data->map.player[Y];
	y = data->map.player[X] + 1;
	if (y == data->map.size[X] || data->map.map_data[x][y] == WALL || data->map.map_data[x][y] == EXIT)
	{
		data->map.map_data[x][y - 1] = PLAYER;
		return (RUN);
	}
	if (data->map.map_data[x][y] == ENEMIES)
		return (LOSE);
	if (data->map.map_data[x][y] == OPEN_EXIT)
		return (WIN);
	right_player_update(data, x, y);
	data->map.player[X]++;
	whole_map_update(data, x, y - 1);
	return (RUN);
}
