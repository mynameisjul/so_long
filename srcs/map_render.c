/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:18:11 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/14 16:19:26 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_border(void *mlx, t_map map)
{
	int	i;
	
	i = 1;
	if (push_tile(mlx, T_TL, 0, 0) == 0
		|| push_tile(mlx, T_TR, map.size[X] - 1, 0) == 0
		|| push_tile(mlx, T_BL, 0, map.size[Y] - 1) == 0
		|| push_tile(mlx, T_BR, map.size[X] - 1, map.size[Y] - 1) == 0)
		return (0);
	while (i < map.size[X])
	{
		if (push_tile(mlx, T_TOP, i, 0) == 0
			|| push_tile(mlx, T_BOTT, i, map.size[Y] - 1) == 0)
			return (0);
		i++;
	}
	i = 1;
	while (i < map.size[Y])
	{
		if (push_tile(mlx, T_LEFT, 0, i) == 0
			|| push_tile(mlx, T_RIGHT, map.size[X] - 1, i) == 0)
			return (0);
		i++;
	}
	return (1);
}
