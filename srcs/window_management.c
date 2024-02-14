/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:44:39 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/14 16:41:24 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*create_window(int x, int y)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if (!mlx)
		return (ft_dprintf(2, WINDOW), NULL);
	mlx_win = mlx_new_window(mlx, x * TILE, (y + 2) * TILE, NAME);
	if (!mlx_win)
		return (ft_dprintf(2, WINDOW), NULL);
	return (mlx);
}

int	push_tile(void *mlx, char *relative_path, int x, int y)
{
	int	a;
	int	b;
	
	a = x * TILE;
	b = y * TILE;
	if (mlx_xpm_file_to_image(mlx, relative_path, &a, &b) == 0)
		return (ft_dprintf(2, LOAD_ASSETS), 0);
	return (1);
}

// void	free_all(void *mlx, void *mlx_win, t_img *img)
// {
// 	mlx_destroy_image(mlx, img);
// 	mlx_destroy_display(mlx);
// 	mlx_clear_window(mlx, mlx_win);
// 	mlx_destroy_window(mlx, mlx_win);
// 	free(mlx);
// }

// void	terminate_window(void *mlx, void *mlx_win, t_img *img)
// {
// 	mlx_hook(mlx_win, 17, 0, mlx_loop_end, mlx);
// 	mlx_loop(mlx);
// 	free_all(mlx, mlx_win, img);
// }
