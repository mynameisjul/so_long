/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:18:11 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/21 14:29:19 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int push_tile(t_mlx_data mlx, void *asset, int x_coord, int y_coord)
{
	int	x;
	int	y;
	
	x = x_coord * TILE;
	y = y_coord * TILE;
	if (mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, asset, x, y) == - 1)
		return (0);
	return (1);
}

int	render_bottom_margin(t_data *data)
{
	int	i;
	
	i = 1;
	if (push_tile(data->mlx, data->assets[T_LOWERBORDER], 0, data->map.size[Y]) == 0
		|| push_tile(data->mlx, data->assets[T_LOWERBORDER], data->map.size[X] - 1,
						data->map.size[Y]) == 0)
		return (0);
	while (i < data->map.size[X] - 1)
 	{
		if (push_tile(data->mlx, data->assets[T_LOWERBORDER], i, data->map.size[Y]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	render_border(t_data *data)
{
	int	i;
	
	i = 1;
	if (push_tile(data->mlx, data->assets[T_TL], 0, 0) == 0
		|| push_tile(data->mlx, data->assets[T_TR], data->map.size[X] - 1, 0) == 0
		|| push_tile(data->mlx, data->assets[T_BL], 0, data->map.size[Y] - 1) == 0
		|| push_tile(data->mlx, data->assets[T_BR], data->map.size[X] - 1,
						data->map.size[Y] - 1) == 0)
		return (0);
	while (i < data->map.size[X] - 1)
 	{
		if (push_tile(data->mlx, data->assets[T_TOP], i, 0) == 0
			|| push_tile(data->mlx, data->assets[T_BOTT], i, data->map.size[Y] - 1) == 0)
			return (0);
		i++;
	}
	i = 1;
	while (i < data->map.size[Y] - 1)
	{
		if (push_tile(data->mlx, data->assets[T_LEFT], 0, i) == 0
			|| push_tile(data->mlx, data->assets[T_RIGHT], data->map.size[X] - 1, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	render_fix_content(t_mlx_data mlx, t_map map, void **assets)
{
	int	x;
	int	y;
	int	ok;

	x = 1;
	y = 1;
	ok = 1;
	while (y < map.size[Y] - 1)
	{
		while (x < map.size[X] - 1)
		{
			if (map.map_data[y][x] == WALL)
				ok = push_tile(mlx, assets[T_WALL], x, y);
			if (map.map_data[y][x] == SPACE)
				ok = push_tile(mlx, assets[T_SPACE], x, y);
			if (map.map_data[y][x] == EXIT)
				ok = push_tile(mlx, assets[T_EXIT], x, y);
			if (ok == 0)
				return (0);
			x++;
		}
		x = 1;
		y++;
	}
	return (1);
}

int	render_moving_content(t_data *data)
{
	int	x;
	int	y;
	int	ok;

	x = 1;
	y = 1;
	ok = 1;
	while (y < data->map.size[Y] - 1)
	{
		while (x < data->map.size[X] - 1)
		{	
			if (data->map.map_data[y][x] == COIN)
				ok = push_tile(data->mlx, data->assets[T_COIN], x, y);
			if (ok == 0)
				return (0);
			x++;
		}
		x = 1;
		y++;
	}
	return (1);
}
