/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:33:28 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/21 14:09:37 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int render_player_right(t_data *data)
{
	int ok;

	ok = 0;
	if (data->count < SPEED)
		ok = push_tile(data->mlx, data->assets[T_P1], data->map.player[X],
					   data->map.player[Y]);
	if (data->count >= SPEED && data->count < 2 * SPEED)
		ok = push_tile(data->mlx, data->assets[T_P2], data->map.player[X],
					   data->map.player[Y]);
	if (data->count >= 2 * SPEED && data->count < 3 * SPEED)
		ok = push_tile(data->mlx, data->assets[T_P3], data->map.player[X],
					   data->map.player[Y]);
	if (data->count >= 3 * SPEED && data->count < 4 * SPEED)
		ok = push_tile(data->mlx, data->assets[T_P4], data->map.player[X],
					   data->map.player[Y]);
	data->count += 1;
	if (data->count == 4 * SPEED)
		data->count = 0;
	return (ok);
}

int render_player_left(t_data *data)
{
	int ok;

	ok = 0;
	if (data->count < SPEED)
		ok = push_tile(data->mlx, data->assets[T_LP1], data->map.player[X],
					   data->map.player[Y]);
	if (data->count >= SPEED && data->count < 2 * SPEED)
		ok = push_tile(data->mlx, data->assets[T_LP2], data->map.player[X],
					   data->map.player[Y]);
	if (data->count >= 2 * SPEED && data->count < 3 * SPEED)
		ok = push_tile(data->mlx, data->assets[T_LP3], data->map.player[X],
					   data->map.player[Y]);
	if (data->count >= 3 * SPEED && data->count < 4 * SPEED)
		ok = push_tile(data->mlx, data->assets[T_LP4], data->map.player[X],
					   data->map.player[Y]);
	data->count += 1;
	if (data->count == 4 * SPEED)
		data->count = 0;
	return (ok);
}

int render_player_coin(t_data *data)
{
	int x;
	int y;

	x = data->map.player[Y];
	y = data->map.player[X];
	if (data->map.map_data[x][y] == LPLAY_ON_COIN)
		return (push_tile(data->mlx, data->assets[T_LPLAYER_COIN], data->map.player[X],
						  data->map.player[Y]));
	if (data->map.map_data[x][y] == LPLAY_ON_CCOIN)
		return (render_player_left(data));
	if (data->map.map_data[x][y] == PLAY_ON_COIN)
		return (push_tile(data->mlx, data->assets[T_PLAYER_COIN], data->map.player[X],
						  data->map.player[Y]));
	if (data->map.map_data[x][y] == PLAY_ON_CCOIN)
		return (render_player_right(data));
	return (0);
}

int render_player(t_data *data)
{
	int x;
	int y;

	x = data->map.player[Y];
	y = data->map.player[X];
	if (data->map.map_data[x][y] == ENEMIES || data->map.map_data[x][y] == LENEMIES)
		return (custom_loop_end(data), 0);
	if (data->map.map_data[x][y] == PLAYER)
		return (render_player_right(data));
	else if (data->map.map_data[x][y] == LPLAYER)
		return (render_player_left(data));
	else
		return (render_player_coin(data));
}
