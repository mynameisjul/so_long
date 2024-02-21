/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:18:05 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/21 14:23:16 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*add_nbr_to_char(int n, char *str)
{
	char	*nbr;
	char	*result;
	
	nbr = ft_itoa(n);
	result = ft_strjoin(str, nbr);
	return (free(nbr), result);
}

int	render(t_data *data)
{
	if (data->win == LOSE)
		return (ft_printf(GAME_LOST), custom_loop_end(data), 0);
	if (render_moving_content(data) == 0
		|| render_player(data) == 0)
		{
		if (data->steps == 0)
			return (ft_dprintf(2, LOAD_ASSETS), 0);
		else
			return (ft_printf(GAME_LOST), custom_loop_end(data), 0);
		}
	if (data->map.enemy > 0)
	{
		if (data->enemy_speed == SPEED * 10)
			move_enemies(data);
		data->enemy_speed++;
		if (+data->enemy_speed > SPEED * 10)
			data->enemy_speed = 0;
		if (data->win != LOSE)
			render_enemies(data);
		if (data->win == LOSE)
			return(ft_printf(GAME_LOST), custom_loop_end(data));
	}
	return (1);
}

int	render_counts(t_data *data)
{
	char	*level;
	char	*steps;

	level = NULL;
	if (render_bottom_margin(data) == 0)
		return (0);
	if (data->level != -1)
		level = add_nbr_to_char(data->level, "Level number ");
	steps = add_nbr_to_char(data->steps, "Number of steps = ");
	if (level)
	{
		mlx_string_put(data->mlx.mlx, data->mlx.mlx_win,
						TILE, (data->map.size[Y] + 1) * TILE - 5, 0x0, level);
		free(level);
	}
	if (steps)
	{
		mlx_string_put(data->mlx.mlx, data->mlx.mlx_win,
						TILE, data->map.size[Y] * TILE + TILE / 2 - 5, 0x0, steps);
		free(steps);
	}
	return (1);
}
