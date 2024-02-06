/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:32:54 by julieblaye        #+#    #+#             */
/*   Updated: 2024/01/26 15:41:49 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello World!");
	img.img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//draw_line(a, b, &img, 0x00FF0000);

	t_coord a = {HWIDTH - 25, HHEIGHT - 25, 0};
	t_coord b = {HWIDTH - 25, HHEIGHT + 25, 0};
	t_coord c = {HWIDTH + 25, HHEIGHT - 25, 0};
	t_coord d = {HWIDTH + 25, HHEIGHT + 25, 0};
	// my_mlx_pixel_put(&img, a.x, a.y, 0x00FF0000);
	// my_mlx_pixel_put(&img, b.x, b.y, 0x00FF0000);
	// my_mlx_pixel_put(&img, c.x, c.y, 0x00FF0000);
	// my_mlx_pixel_put(&img, d.x, d.y, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, 0);
	// a = x_rotation(a, deg_to_rad(45));
	// b = x_rotation(b, deg_to_rad(45));
	// c = x_rotation(c, deg_to_rad(45));
	// d = x_rotation(d, deg_to_rad(45));
	// a = y_rotation(a, deg_to_rad(45));
	// b = y_rotation(b, deg_to_rad(45));
	// c = y_rotation(c, deg_to_rad(45));
	// d = y_rotation(d, deg_to_rad(45));
	my_mlx_pixel_put(&img, a.x, a.y, 0x00FF0000);
	my_mlx_pixel_put(&img, b.x, b.y, 0x00FF0000);
	my_mlx_pixel_put(&img, c.x, c.y, 0x00FF0000);
	my_mlx_pixel_put(&img, d.x, d.y, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, 0);
	mlx_hook(mlx_win, 17, 0, mlx_loop_end, mlx);
	mlx_loop(mlx);
	//free_all(mlx, mlx_win, &img);
	return (0);
}