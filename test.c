/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:32:54 by julieblaye        #+#    #+#             */
/*   Updated: 2024/02/07 16:30:28 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/so_long.h"

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

	mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, 0);
	mlx_hook(mlx_win, 17, 0, mlx_loop_end, mlx);
	mlx_loop(mlx);
	//free_all(mlx, mlx_win, &img);
	return (0);
}