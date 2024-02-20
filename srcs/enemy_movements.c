/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:56:38 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/20 12:17:37 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_single_enemy(t_data *data, int x, int y)
{
	int	rand;

	rand = ft_rand_range(4);
	if (rand == 1)
		return (move_single_enemy_up(data, x, y));
	if (rand == 2)
		return (move_single_enemy_down(data, x, y));
	if (rand == 3)
		return (move_single_enemy_left(data, x, y));
	return (move_single_enemy_right(data, x, y));
}

int	move_enemies(t_data *data)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < data->map.size[Y])
	{
		while (x < data->map.size[X])
		{
			if (data->map.map_data[y][x] == ENEMIES)
				ok = render_enemy_right(data, x, y);
			if (data->map.map_data[y][x] == LENEMIES)
				ok = render_enemy_left(data, x,y);
			if (ok == 0)
				return (ft_dprintf(2, LOAD_ASSETS), 0);
			x++;
		}
		x = 1;
		y++;
	}
}
