/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:53:23 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/19 14:00:43 by jblaye           ###   ########.fr       */
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
	if (data->map.nb_coins == 0)
		data->map.map_data[data->map.exit[Y]][data->map.exit[X]] = OPEN_EXIT;
}
