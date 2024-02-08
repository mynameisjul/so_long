/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:44:39 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/08 12:35:36 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	create_window(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if (!mlx)
		return (-1);
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello World!");
	if (!mlx_win)
		return (-1);
	return (0);
}

int	push_image(void *mlx, void *mlx_win)
{
	t_img	img;

	img.img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, 0);
	if (!img.img_ptr)
		return (-1);
	return (0);
}

void	free_all(void *mlx, void *mlx_win, t_img *img)
{
	mlx_destroy_image(mlx, img);
	mlx_destroy_display(mlx);
	mlx_clear_window(mlx, mlx_win);
	mlx_destroy_window(mlx, mlx_win);
	free(mlx);
}

void	terminate_window(void *mlx, void *mlx_win, t_img *img)
{
	mlx_hook(mlx_win, 17, 0, mlx_loop_end, mlx);
	mlx_loop(mlx);
	free_all(mlx, mlx_win, img);
}
