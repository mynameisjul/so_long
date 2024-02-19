/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:40:45 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/19 12:33:59 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

int	level_margin_render(t_data *data)
{
	int	i;

	i = 0;
	while (i < LEVEL_SIZE)
 	{
		if (push_tile(data->mlx, data->assets[T_LOWERBORDER], i, 0) == 0
			|| push_tile(data->mlx, data->assets[T_LOWERBORDER], i, LEVEL_SIZE - 1) == 0)
			return (0);
		i++;
	}
	i = 1;
	while (i <  LEVEL_SIZE - 1)
	{
		if (push_tile(data->mlx, data->assets[T_LOWERBORDER], 0, i) == 0
			|| push_tile(data->mlx, data->assets[T_LOWERBORDER], LEVEL_SIZE - 1, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	level_border_render(t_data	*data)
{
	int	i;
	
	i = 1;
	if (push_tile(data->mlx, data->assets[T_TL], 1, 1) == 0
		|| push_tile(data->mlx, data->assets[T_TR], LEVEL_SIZE - 2, 1) == 0
		|| push_tile(data->mlx, data->assets[T_BL], 1, LEVEL_SIZE - 2) == 0
		|| push_tile(data->mlx, data->assets[T_BR], LEVEL_SIZE - 2,
						LEVEL_SIZE - 2) == 0)
		return (0);
	while (i < LEVEL_SIZE - 1)
 	{
		if (push_tile(data->mlx, data->assets[T_TOP], i, 1) == 0
			|| push_tile(data->mlx, data->assets[T_BOTT], i, LEVEL_SIZE - 2) == 0)
			return (0);
		i++;
	}
	i = 1;
	while (i <  LEVEL_SIZE - 2)
	{
		if (push_tile(data->mlx, data->assets[T_LEFT], 1, i) == 0
			|| push_tile(data->mlx, data->assets[T_RIGHT], LEVEL_SIZE - 2, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	level_fill(t_data *data)
{
	int	x;
	int	y;
	
	x = 2;
	y = 2;
	while (y < LEVEL_SIZE - 1)
	{
		while (x < LEVEL_SIZE - 1)
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
	if (data->level == -1)
		return (mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, TILE * 2,
								TILE * 3, 0xd2691e, "Press 'n' to start"), 1);
	if (data->level < 10)
	return (mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, TILE * 2,
								TILE * 3, 0xd2691e, "Congratulations! You won! Press 'n' to go to the next level"), 1);
	if (data->level == 10)
		return (mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, TILE * 2,
								TILE * 3, 0xd2691e, "Congratulations! You won the game"), 1);
	return (0);
}

char	*level_char(int	level)
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
