/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:32:54 by julieblaye        #+#    #+#             */
/*   Updated: 2024/02/08 12:29:33 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/so_long.h"

int	main(int ac, char **av)
{
	(void) ac;
	// void	*mlx;
	// void	*mlx_win;
	// t_img	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello World!");
	// img.img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
	// img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);

	// mlx_put_image_to_window(mlx, mlx_win, img.img_ptr, 0, 0);
	// mlx_hook(mlx_win, 17, 0, mlx_loop_end, mlx);
	// mlx_loop(mlx);
	//free_all(mlx, mlx_win, &img);
	int len = ft_strlen(av[1]);
	int i = -1;
	if (len > 4)
		i = ft_strncmp(&av[1][len - 4], ".ber", 5);
	printf("%d\n",i);
	return (0);
}