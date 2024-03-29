/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:32:29 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/21 18:24:50 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	init_tmap(t_map *map)
{
	map->map_data = NULL;
	map->fd = -1;
	map->isvalid = 0;
	map->size[X] = 0;
	map->size[Y] = 0;
	map->nb_coins = 0;
	map->player[X] = -1;
	map->player[Y] = -1;
	map->exit[X] = -1;
	map->exit[Y] = -1;
	map->enemy = 0;
	return (*map);
}

t_data	init_tdata(t_data *data)
{
	init_tmap(&(data->map));
	data->mlx.mlx = NULL;
	data->mlx.mlx_win = NULL;
	data->count = 0;
	data->steps = 0;
	data->level = -1;
	data->win = RUN;
	data->enemy_speed = 0;
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
	return (map->fd);
}

int	isvalidmapchar(char c)
{
	if ((c == ENEMIES || c == LENEMIES) && BONUS == 1)
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
