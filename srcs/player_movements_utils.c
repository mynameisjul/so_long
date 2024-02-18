/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:53:23 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/16 20:15:24 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void left_player_update(t_data *data, int x, int y)
{
	if (data->map.map_data[x][y] == SPACE)
	{
		data->map.map_data[x][y] = LPLAYER;
		return;
	}
	if (data->map.map_data[x][y] == COIN)
	{
		data->map.map_data[x][y] = LPLAY_ON_COIN;
		data->map.nb_coins--;
		return;
	}
	if (data->map.map_data[x][y] == COL_COIN)
	{
		data->map.map_data[x][y] = LPLAY_ON_CCOIN;
		return;
	}
}

void right_player_update(t_data *data, int x, int y)
{
	if (data->map.map_data[x][y] == SPACE)
	{
		data->map.map_data[x][y] = PLAYER;
		return;
	}
	if (data->map.map_data[x][y] == COIN)
	{
		data->map.map_data[x][y] = PLAY_ON_COIN;
		data->map.nb_coins--;
		return;
	}
	if (data->map.map_data[x][y] == COL_COIN)
	{
		data->map.map_data[x][y] = PLAY_ON_CCOIN;
		return;
	}
}

void whole_map_update(t_data *data, int x, int y)
{
	if (data->map.map_data[x][y] == PLAY_ON_COIN || data->map.map_data[x][y] == PLAY_ON_CCOIN || data->map.map_data[x][y] == LPLAY_ON_COIN || data->map.map_data[x][y] == LPLAY_ON_CCOIN)
		data->map.map_data[x][y] = COL_COIN;
	if (data->map.map_data[x][y] == PLAYER || data->map.map_data[x][y] == LPLAYER)
		data->map.map_data[x][y] = SPACE;
	// if ()
	if (data->map.nb_coins == 0)
		data->map.map_data[data->map.exit[Y]][data->map.exit[X]] = OPEN_EXIT;
}

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
