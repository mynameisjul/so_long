/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_enemy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:58:35 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/21 15:40:10 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_enemy_right(t_data *data, int x, int y)
{
	if (BONUS == 1)
	{
		if (data->count < SPEED)
			return (push_tile(data->mlx, data->assets[T_E1], x, y));
		if (data->count >= SPEED && data->count < 2 * SPEED)
			return (push_tile(data->mlx, data->assets[T_E2], x, y));
		if (data->count >= 2 * SPEED && data->count < 3 * SPEED)
			return (push_tile(data->mlx, data->assets[T_E3], x, y));
		if (data->count >= 3 * SPEED && data->count < 4 * SPEED)
			return (push_tile(data->mlx, data->assets[T_E4], x, y));
	}
	else
		return (push_tile(data->mlx, data->assets[T_E3], x, y));
	return (0);
}

int	render_enemy_left(t_data *data, int x, int y)
{
	if (BONUS == 1)
	{
		if (data->count < SPEED)
			return (push_tile(data->mlx, data->assets[T_LE1], x, y));
		if (data->count >= SPEED && data->count < 2 * SPEED)
			return (push_tile(data->mlx, data->assets[T_LE2], x, y));
		if (data->count >= 2 * SPEED && data->count < 3 * SPEED)
			return (push_tile(data->mlx, data->assets[T_LE3], x, y));
		if (data->count >= 3 * SPEED && data->count < 4 * SPEED)
			return (push_tile(data->mlx, data->assets[T_LE4], x, y));
	}
	else
		return (push_tile(data->mlx, data->assets[T_LE3], x, y));
	return (0);
}

int	render_enemies(t_data *data)
{
	int	x;
	int	y;
	int	ok;

	x = 1;
	y = 1;
	ok = 1;
	while (y < data->map.size[Y])
	{
		while (x < data->map.size[X])
		{
			if (data->map.map_data[y][x] == ENEMIES)
				ok = render_enemy_right(data, x, y);
			if (data->map.map_data[y][x] == LENEMIES)
				ok = render_enemy_left(data, x, y);
			if (ok == 0)
				return (ft_dprintf(2, LOAD_ASSETS), 0);
			x++;
		}
		x = 1;
		y++;
	}
	return (1);
}
