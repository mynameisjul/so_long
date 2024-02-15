/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:18:11 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/15 17:01:48 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// t_img	generate_image(t_map map, t_mlx_data mlx)
// {
// 	t_img	img;
	
// 	img.img_ptr = mlx_new_image(mlx.mlx, map.size[X] * TILE, map.size[Y] * TILE);
// 	if (!img.img_ptr)
// 		return (img);
// 	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
// 								&img.line_length, &img.endian);
// 	//mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img_ptr, 0, 0);
// 	return (img);
// }

int push_tile(t_mlx_data mlx, void *asset, int x_coord, int y_coord)
{
	int	x;
	int	y;
	
	x = x_coord * TILE;
	y = y_coord * TILE;
	if (mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, asset, x, y) == 0)
		return (0);
	return (1);
}

int	render_border(t_mlx_data mlx, t_map map, void **assets)
{
	int	i;
	
	i = 1;
	if (push_tile(mlx, assets[T_TL], 0, 0) == 0
		|| push_tile(mlx, assets[T_TR], map.size[X] - 1, 0) == 0
		|| push_tile(mlx, assets[T_BL], 0, map.size[Y] - 1) == 0
		|| push_tile(mlx, assets[T_BR], map.size[X] - 1, map.size[Y] - 1) == 0)
		return (0);
	while (i < map.size[X] - 1)
 	{
		if (push_tile(mlx, assets[T_TOP], i, 0) == 0
			|| push_tile(mlx, assets[T_BOTT], i, map.size[Y] - 1) == 0)
			return (0);
		i++;
	}
	i = 1;
	while (i < map.size[Y] - 1)
	{
		if (push_tile(mlx, assets[T_LEFT], 0, i) == 0
			|| push_tile(mlx, assets[T_RIGHT], map.size[X] - 1, i) == 0)
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
			if (map.map_data[y][x] == EXIT)
				ok = push_tile(mlx, assets[T_EXIT], x, y);
			if (map.map_data[y][x] == SPACE)
				ok = push_tile(mlx, assets[T_SPACE], x, y);
			if (ok == 0)
				return (ft_dprintf(2, LOAD_ASSETS), 0);
			x++;
		}
		x = 1;
		y++;
	}
	return (1);
}

int	render_moving_content(t_mlx_data mlx, t_map map, void **assets)
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
			if (map.map_data[y][x] == COIN)
				ok = push_tile(mlx, assets[T_COIN], x, y);
			if (map.map_data[y][x] == PLAYER)
				ok = push_tile(mlx, assets[T_PLAYER], x, y);
			if (map.map_data[y][x] == ENEMIES)
				ok = push_tile(mlx, assets[T_ENEMY], x, y);
			if (ok == 0)
				return (ft_dprintf(2, LOAD_ASSETS), 0);
			x++;
		}
		x = 1;
		y++;
	}
	return (1);
}
