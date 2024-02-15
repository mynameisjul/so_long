/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:44:39 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/15 17:58:57 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_mlx_data	create_window(int x, int y)
{
	t_mlx_data	result;

	result.mlx_win = NULL;
	result.mlx = mlx_init();
	if (!result.mlx)
		return (ft_dprintf(2, WINDOW), result);
	result.mlx_win = mlx_new_window(result.mlx, x * TILE, (y + 1) * TILE, NAME);
	if (!result.mlx_win)
		return (ft_dprintf(2, WINDOW), result);
	
	return (result);
}



void	free_all(void *mlx, void *mlx_win, void **assets)
{
	int	i;

	i = NB_ASSETS;
	while (i > 0)
	{
		mlx_destroy_image(mlx, assets[i - 1]);
		i--;
	}
	mlx_destroy_display(mlx);
	mlx_clear_window(mlx, mlx_win);
	mlx_destroy_window(mlx, mlx_win);
	free(mlx);
}

void	terminate_window(t_mlx_data mlx, t_map *map, void **assets)
{
	mlx_hook(mlx.mlx_win, 17, 0, mlx_loop_end, mlx.mlx);
	mlx_key_hook(mlx.mlx_win, ft_hook, map);
	mlx_loop(mlx.mlx);
	free_all(mlx.mlx, mlx.mlx_win, assets);
}
