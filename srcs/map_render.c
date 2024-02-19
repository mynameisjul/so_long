/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:18:05 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/19 15:13:49 by jblaye           ###   ########.fr       */
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
	if(render_border(data) == 0
		|| render_fix_content(data->mlx, data->map, data->assets) == 0
		|| render_moving_content(data->mlx, data->map, data->assets) == 0
		|| render_player(data) == 0)
		return (ft_dprintf(2, LOAD_ASSETS), 0);
	return (1);
}

int	render_counts(t_data *data)
{
	char	*level;
	char	*steps;

	if (render_bottom_margin(data) == 0)
		return (0);
	level = add_nbr_to_char(data->level, "Level number ");
	steps = add_nbr_to_char(data->steps, "Number of steps = ");
	if (level)
		mlx_string_put(data->mlx.mlx, data->mlx.mlx_win,
						TILE, (data->map.size[Y] + 1) * TILE - 5, 0x0, level);
	if (steps)
		mlx_string_put(data->mlx.mlx, data->mlx.mlx_win,
						TILE, data->map.size[Y] * TILE + TILE / 2 - 5, 0x0, steps);
	return (1);
}