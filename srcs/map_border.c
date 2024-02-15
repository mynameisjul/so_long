/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:25:33 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/15 17:31:00 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int	rgb(int red, int green, int blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }


// void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	push_border(void *mlx, void *mlx_win, t_map map)
// {
// 	t_img	img;

	
// 	img.img_ptr = mlx_new_image(mlx, map.size[X], TILE);
// 	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, map.size[Y] * TILE);
// 	if (!img.img_ptr)
// 		return (-1);
// 	return (0);
// }