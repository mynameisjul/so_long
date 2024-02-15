/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:45:12 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/15 18:01:54 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_hook(int	keycode, t_map *map)
{
	(void) keycode;
	map->player[X]++;
	map->map_data[map->player[Y]][map->player[X] - 1] = SPACE;
	push_tile()
	map->map_data[map->player[Y]][map->player[X]] = PLAYER;
	printf("ca bouge\n");
	return (1);
}