/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:45:30 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/12 16:06:41 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	init_tmap(t_map *map)
{
	map->map_data = NULL;
	map->fd = -1;
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

int	valid_wall_line(t_map map, char *line, int last)
{
	int	isvalid;
	int	len;
	int	i;

	isvalid = 0;
	i = 0;
	if (line)
	{
		len = (int) ft_strlen(line);
		if (last == 0)
			len--;
		while (line[i] == WALL)
			i++;
		if (last == 0 && line[i] == '\n' && len == map.size[X])
			isvalid = 1;
		if (last == 1 && line[i] == 0 && len == map.size[X])
			isvalid = 1;
	}
	return (isvalid);
}

int	valid_line(t_map *map, char	*line)
{
	int	i;
	int	isvalid;

	i = 0;
	isvalid = 0;
	if (line)
	{
		while (line[i] != '\n' && line[i] != 0)
		{
			if (line[i] != WALL && line[i] != COIN && line[i] != SPACE
				&& line[i] != EXIT && line[i] != PLAYER)
				return (isvalid);
			if (line[i] == PLAYER)
				map->player++;
			if (line[i] == EXIT)
				map->exit++;
			if (line[i] == COIN)
				map->nb_coins++;
			i++;
		}
		if (i == map->size[X] && line[0] == WALL && line[i - 1] == WALL)
			return (1);
	}
	return (isvalid);
}
