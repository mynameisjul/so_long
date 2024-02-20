/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:56:38 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/20 16:07:39 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	index_n_non_null(int *tab, int len, int n)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (n == 1 && tab[i] != 0)
			return (i);
		if (tab[i] != 0)
			n--;
		i++;
	}
	return (-1);
}

int	valid_enemy_destination(t_data *data, int x, int y)
{
	if (data->map.map_data[y][x] == SPACE
		|| data->map.map_data[y][x] == PLAY_ON_CCOIN
		|| data->map.map_data[y][x] == PLAY_ON_COIN
		|| data->map.map_data[y][x] == PLAYER
		|| data->map.map_data[y][x] == LPLAY_ON_CCOIN
		|| data->map.map_data[y][x] == LPLAY_ON_COIN
		|| data->map.map_data[y][x] == LPLAYER)
		return (1);
	return (0);
}

int	move_single_enemy(t_data *data, int x, int y)
{
	int	rand;
	int	*moves;
	int	i;

	moves = (int []) {valid_enemy_destination(data, x, y - 1),
			valid_enemy_destination(data, x, y + 1),
			valid_enemy_destination(data, x - 1, y),
			valid_enemy_destination(data, x + 1, y),
			0};
	moves[4] = moves[0] + moves[1] + moves[2] + moves[3];
	if (moves[4] == 0)
		return (1);
	rand = ft_rand_range(moves[4]);
	i = index_n_non_null(moves, 4, rand);
	if (i == 0)
		return (move_single_enemy_up(data, x, y));
	if (i == 1)
		return ( move_single_enemy_down(data, x, y));
	if (i == 2)
		return (move_single_enemy_left(data, x, y));
	if (i == 3)
		return (move_single_enemy_right(data, x, y));
	if (i == -1)
		return (1);
	return (1);
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
			if (data->map.map_data[y][x] == ENEMIES
				||data->map.map_data[y][x] == LENEMIES)
				data->win = move_single_enemy(data, x, y);
			if (data->win == LOSE)
				return (LOSE);
			x++;
		}
		x = 1;
		y++;
	}
	return (RUN);
}
