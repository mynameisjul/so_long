/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:27:08 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/21 15:01:24 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	recurs_path_find(t_map *cp, t_map map, int x, int y)
{
	if (cp->map_data[y][x] == EXIT)
		cp->exit[X] = 1;
	if (cp->map_data[y][x] == WALL || cp->map_data[y][x] == EXIT)
		return (0);
	if (cp->map_data[y][x] == COIN)
		cp->nb_coins++;
	cp->map_data[y][x] = WALL;
	if (y - 1 > 0 && !(cp->map_data[y - 1][x] == '1'
		|| ((cp->map_data[y - 1][x] == 'X' || cp->map_data[y - 1][x] == 'x')
		&& BONUS == 1)))
		recurs_path_find(cp, map, x, y - 1);
	if (y + 1 < map.size[Y] && !(cp->map_data[y + 1][x] == '1'
		|| ((cp->map_data[y + 1][x] == 'X' || cp->map_data[y + 1][x] == 'x')
		&& BONUS == 1)))
		recurs_path_find(cp, map, x, y + 1);
	if (x + 1 < map.size[X] && !(cp->map_data[y][x + 1] == '1'
		|| ((cp->map_data[y][x + 1] == 'X' || cp->map_data[y][x + 1] == 'x')
		&& BONUS == 1)))
		recurs_path_find(cp, map, x + 1, y);
	if (x - 1 > 0 && !(cp->map_data[y][x - 1] == '1'
		|| ((cp->map_data[y][x - 1] == 'X' || cp->map_data[y][x - 1] == 'x')
		&& BONUS == 1)))
		recurs_path_find(cp, map, x - 1, y);
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
		if (!path_map.map_data[count])
			return (ft_dprintf(2, MALLOC_ERR), ft_fsplit(path_map.map_data), 0);
		count++;
	}
	path_map.map_data[count] = 0;
	recurs_path_find(&path_map, *map, map->player[X], map->player[Y]);
	ft_fsplit(path_map.map_data);
	if (path_map.nb_coins == map->nb_coins && path_map.exit[X] == 1)
		return (1);
	return (ft_dprintf(2, NO_PATH), 0);
}
