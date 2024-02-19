/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:45:12 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/19 12:34:59 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_hook(int keycode, t_data *data)
{
	int	steps;
	int	win;

	steps = data->steps;
	if (keycode == ESCAPE)
		mlx_loop_end(data->mlx.mlx);
	if (keycode == UP)
		win = player_up(data);
	if (keycode == DOWN)
		win = player_down(data);
	if (keycode == LEFT)
		win = player_left(data);
	if (keycode == RIGHT)
		win = player_right(data);
	if (data->steps > steps)
		ft_printf("Number of steps = %d\n", data->steps);
	if (win == WIN)
	{
		data->level++;
		mlx_loop_end(data->mlx.mlx);
	}
	if (win == LOSE)
		mlx_loop_end(data->mlx.mlx);
	return (win);
}

int ft_level_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		return (mlx_loop_end(data->mlx.mlx), 0);
	if (keycode == 'n')
	{
		data->level++;
		return (mlx_loop_end(data->mlx.mlx), 1);
	}
	return (0);
}
