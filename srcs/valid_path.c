/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:27:08 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/16 20:22:47 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int recurs_path_find(char **m, t_map *cpmap, t_map map, int x, int y)
{
	if (m[y][x] == EXIT)
		cpmap->exit[X] = 1;
	if (m[y][x] == WALL || m[y][x] == EXIT)
		return (0);
	if (m[y][x] == COIN)
		cpmap->nb_coins++;
	m[y][x] = WALL;
	if (y - 1 > 0 && !(m[y - 1][x] == '1' || (m[y - 1][x] == 'X' && BONUS == 1)))
		recurs_path_find(m, cpmap, map, x, y - 1);
	if (y + 1 < map.size[Y]
		&& !(m[y + 1][x] == '1' || (m[y + 1][x] == 'X' && BONUS == 1)))
		recurs_path_find(m, cpmap, map, x, y + 1);
	if (x + 1 < map.size[X]
		&& !(m[y][x + 1] == '1' || (m[y][x + 1] == 'X' && BONUS == 1)))
		recurs_path_find(m, cpmap, map, x + 1, y);
	if (x - 1 > 0 && !(m[y][x - 1] == '1' || (m[y][x - 1] == 'X' && BONUS == 1)))
		recurs_path_find(m, cpmap, map, x - 1, y);
	return (0);
}

int	find_path(t_map *map)
{
	t_map	path_map;
	int		count;

	count = 0;
	init_tmap(&path_map);
	path_map.map_data = (char **) ft_calloc(map->size[Y] + 1, sizeof(char *));
	if (!path_map.map_data)
		return (ft_dprintf(2, MALLOC_ERR), 0);
	while (count < map->size[Y])
	{
		path_map.map_data[count] = ft_strdup(map->map_data[count]);
		if(!path_map.map_data[count])
			return (ft_dprintf(2, MALLOC_ERR), ft_fsplit(path_map.map_data), 0);
		count++;
	}
	path_map.map_data[count] = 0;
	recurs_path_find(path_map.map_data, &path_map, *map, map->player[X], map->player[Y]);
	ft_fsplit(path_map.map_data);
	if (path_map.nb_coins == map->nb_coins && path_map.exit[X] == 1)
		return (1);
	return (ft_dprintf(2, NO_PATH), 0);
}
