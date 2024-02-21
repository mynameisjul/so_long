/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:44:39 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/21 17:28:05 by jblaye           ###   ########.fr       */
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

int	custom_loop_end(t_data *data)
{
	data->win = BYE;
	mlx_loop_end(data->mlx.mlx);
	return (BYE);
}

void	free_all(t_data *data)
{
	int	i;

	i = NB_ASSETS;
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
	while (i > 0)
	{
		if (data->assets[i - 1] != 0)
			mlx_destroy_image(data->mlx.mlx, data->assets[i - 1]);
		i--;
	}
	if (data->assets)
		free(data->assets);
	if (data->mlx.mlx && data->mlx.mlx)
	{
		mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
		data->mlx.mlx_win = NULL;
		mlx_destroy_display(data->mlx.mlx);
		data->mlx.mlx == NULL;
	}
	if (data->map.map_data)
		ft_fsplit(data->map.map_data);
	data->map.map_data = NULL;
	data->steps = 0;
	free(data->mlx.mlx);
}

void	terminate_level_window(t_data *data)
{
	render_level_window(data);
	mlx_hook(data->mlx.mlx_win, 17, 0, &custom_loop_end, data);
	mlx_key_hook(data->mlx.mlx_win, ft_level_hook, data);
	mlx_loop(data->mlx.mlx);
	free_all(data);
}

void	terminate_window(t_data *data)
{
	if (render_bottom_margin(data) == 0
		|| render_border(data) == 0
		|| render_counts(data) == 0
		|| render_fix_content(data->mlx, data->map, data->assets) == 0)
	{
		custom_loop_end(data);
		return ;
	}
	mlx_loop_hook(data->mlx.mlx, &render, data);
	mlx_hook(data->mlx.mlx_win, 17, 0, &custom_loop_end, data);
	mlx_key_hook(data->mlx.mlx_win, ft_hook, data);
	mlx_loop(data->mlx.mlx);
	free_all(data);
}
