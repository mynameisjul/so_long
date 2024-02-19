/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:32:29 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/19 13:39:16 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	init_tmap(t_map *map)
{
	map->map_data = NULL;
	map->fd = -1;
	map->isvalid = 0;
	map->player[X] = -1;
	map->player[Y] = -1;
	map->nb_coins = 0;
	map->exit[X] = -1;
	map->exit[Y] = -1;
	map->size[X] = 0;
	map->size[Y] = 0;
	map->enemies = 0;
	return (*map);
}

t_data	init_tdata(t_data *data)
{
	data->map.map_data = NULL;
	data->map.fd = -1;
	data->map.isvalid = 0;
	data->map.player[X] = -1;
	data->map.player[Y] = -1;
	data->map.nb_coins = 0;
	data->map.exit[X] = -1;
	data->map.exit[Y] = -1;
	data->map.size[X] = 0;
	data->map.size[Y] = 0;
	data->map.enemies = 0;
	data->count = 0;
	data->steps = 0;
	data->level = -1;
	data->win = RUN;
	return (*data);
}

int	open_map(char *file_name, t_map *map)
{
	int	len;

	map->fd = -1;
	if (file_name)
	{
		len = ft_strlen(file_name);
		if (ft_strncmp(&file_name[len - 4], ".ber", 5) == 0 && len > 4)
			map->fd = open(file_name, O_RDONLY, 0644);
	}
	if (map->fd == -1)
		ft_dprintf(2, "Could not open map file\n");
	return (map->fd);
}

int	isvalidmapchar(char c)
{
	if (BONUS == 1 && c == ENEMIES)
		return (1);
	if (c != WALL && c != COIN && c != SPACE && c != EXIT && c != PLAYER)
		return (0);
	return (1);
}

int	fetch_element_coordinates(t_map *map, t_read read, int i)
{
	if (read.line[i] == PLAYER)
	{
		if (map->player[X] != -1)
			return (0);
		map->player[X] = i;
		map->player[Y] = read.count - 1;
	}
	if (read.line[i] == EXIT)
	{
		if (map->exit[X] != -1)
			return (0);
		map->exit[X] = i;
		map->exit[Y] = read.count - 1;
	}
	return (1);
}
