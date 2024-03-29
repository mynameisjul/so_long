/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:45:12 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/22 16:31:09 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_hook(int keycode, t_data *data)
{
	int	steps;

	steps = data->steps;
	if (keycode == ESCAPE)
		return (custom_loop_end(data));
	if (data->win != LOSE && (keycode == UP || keycode == DOWN
			|| keycode == RIGHT || keycode == LEFT))
	{
		if (keycode == UP)
			data->win = player_up(data);
		if (keycode == DOWN)
			data->win = player_down(data);
		if (keycode == LEFT)
			data->win = player_left(data);
		if (keycode == RIGHT)
			data->win = player_right(data);
		if ((data->win == WIN || data->win == LOSE) && steps == data->steps)
			data->steps++;
		if (data->win == WIN)
			mlx_loop_end(data->mlx.mlx);
		if (data->steps > steps)
			ft_printf("Number of steps = %d\n", data->steps);
		render_counts(data);
	}
	return (data->win);
}

int	ft_level_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
	{
		mlx_loop_end(data->mlx.mlx);
		data->win = BYE;
		return (data->win);
	}
	if (keycode == 'n')
	{
		data->level++;
		return (mlx_loop_end(data->mlx.mlx), 1);
	}
	return (0);
}
