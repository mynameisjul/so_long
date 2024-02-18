/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:45:12 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/16 20:16:49 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_hook(int keycode, t_data *data)
{
	// if (keycode == EXIT)
	printf("x = %d\ny = %d\n\n", data->map.player[X], data->map.player[Y]);
	if (keycode == UP)
		return (player_up(data));
	if (keycode == DOWN)
		return (player_down(data));
	if (keycode == LEFT)
		return (player_left(data));
	if (keycode == RIGHT)
		return (player_right(data));
	// map->player[X]++;
	// map->map_data[map->player[Y]][map->player[X] - 1] = SPACE;
	// push_tile()
	// map->map_data[map->player[Y]][map->player[X]] = PLAYER;
	// printf("ca bouge\n");
	return (1);
}