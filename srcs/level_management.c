/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:40:45 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/21 17:38:14 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	level_margin_render(t_data *data)
{
	int	i;

	i = 0;
	while (i < LEVEL_SIZE)
	{
		if (push_tile(data->mlx, data->assets[T_LOWBORD], i, 0) == 0
			|| push_tile(data->mlx, data->assets[T_LOWBORD], i, 4) == 0)
			return (0);
		i++;
	}
	i = 1;
	while (i < 5)
	{
		if (push_tile(data->mlx, data->assets[T_LOWBORD], 0, i) == 0
			|| push_tile(data->mlx, data->assets[T_LOWBORD],
				LEVEL_SIZE - 1, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	level_border_render(t_data	*data)
{
	int	i;

	i = 2;
	if (push_tile(data->mlx, data->assets[T_TL], 1, 1) == 0
		|| push_tile(data->mlx, data->assets[T_TR], LEVEL_SIZE - 2, 1) == 0
		|| push_tile(data->mlx, data->assets[T_BL], 1, 3) == 0
		|| push_tile(data->mlx, data->assets[T_BR], LEVEL_SIZE - 2, 3) == 0)
		return (0);
	while (i < LEVEL_SIZE - 2)
	{
		if (push_tile(data->mlx, data->assets[T_TOP], i, 1) == 0
			|| push_tile(data->mlx, data->assets[T_BOTT], i, 3) == 0)
			return (0);
		i++;
	}
	if (push_tile(data->mlx, data->assets[T_LEFT], 1, 2) == 0
		|| push_tile(data->mlx, data->assets[T_RIGHT], LEVEL_SIZE - 2, 2) == 0)
		return (0);
	return (1);
}

int	level_fill(t_data *data)
{
	int	x;
	int	y;

	x = 2;
	y = 2;
	while (y < 3)
	{
		while (x < LEVEL_SIZE - 2)
		{
			if (push_tile(data->mlx, data->assets[T_SPACE], x, y) == 0)
				return (0);
			x++;
		}
		x = 1;
		y++;
	}
	return (1);
}

int	render_level_window(t_data	*data)
{
	if (level_border_render(data) == 0)
		return (ft_dprintf(2, LOAD_ASSETS), 0);
	if (level_fill(data) == 0)
		return (ft_dprintf(2, LOAD_ASSETS), 0);
	if (level_margin_render(data) == 0)
		return (ft_dprintf(2, LOAD_ASSETS), 0);
	if (data->level == -1 || data->level == -2)
	{
		mlx_string_put(data->mlx.mlx, data->mlx.mlx_win,
			TILE * 2, TILE * 3 - TILE / 2, 0x0,
			"Jump over all the obstacles then go to the exit.");
		return (mlx_string_put(data->mlx.mlx, data->mlx.mlx_win,
				TILE * 2, TILE * 3 + TILE / 3, 0x0,
				"Press 'n' to start the game."), 1);
	}
	if (data->level < 5)
		return (mlx_string_put(data->mlx.mlx, data->mlx.mlx_win,
				TILE * 2, TILE * 3 - TILE / 3, 0x0,
				"Congratulations! You won! Press 'n' to go to the next level."),
			1);
	if (data->level == 5)
		return (mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, TILE * 2,
				TILE * 3 - TILE / 3, 0x0,
				"Congratulations! You won the game!"), 1);
	return (0);
}

char	*level_char(int level)
{
	char	*c_level;
	char	*level_char;

	c_level = ft_itoa(level);
	level_char = ft_strjoin("maps/level_", c_level);
	free(c_level);
	if (!level_char)
		return (0);
	level_char = ft_strappend(level_char, ".ber");
	if (!level_char)
		return (0);
	return (level_char);
}
