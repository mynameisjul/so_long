/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:31:49 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/12 16:04:05 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_check(t_map *map)
{
	char	*line;
	int		isvalid;
	int		valid_last_line;

	isvalid = 0;
	valid_last_line = 0;
	oget_next_line(map->fd, &line);
	if (!line)
		return (close(map->fd), 0);
	map->size[X] = ft_strlen(line) - 1;
	map->size[Y] = 1;
	isvalid = valid_wall_line(*map, line, 0);
	if (isvalid == 0)
		return (close(map->fd), free(line), isvalid);
	while (free(line), oget_next_line(map->fd, &line) != 0 && map->size[Y] < 33)
	{
		isvalid = valid_line(map, line);
		if (isvalid == 0)
			return (close(map->fd), free(line), isvalid);
		map->size[Y]++;
		valid_last_line = valid_wall_line(*map, line, 1);
	}
	if (valid_last_line == 0)
		return (close(map->fd), 0);
	return (close(map->fd), isvalid);
}

int	map_check_norminette(t_map map)
{
	if (map.player != 1 || map.nb_coins < 1 || map.exit != 1)
		return (0);
	return (1);
}

int	map_error(t_map *map)
{
	if (map->fd != -1)
		close(map->fd);
	if (map->map_data && map->map_data[0] != 0)
		ft_fsplit(map->map_data);
	return (0);
}

int	map_parsing(char *file, t_map *map)
{
	char	*line;
	int		i;

	i = 0;
	if (open_map(file, map) == -1)
		return (0);
	if (map_check(map) == 0 || map_check_norminette(*map) == 0)
		return (ft_dprintf(2, INVALID_MAP), 0);
	if (map->size[X] > MAX_WIDTH || map->size[Y] > MAX_HEIGHT)
		return (ft_dprintf(2, OVERSIZE_MAP), 0);
	if (open_map(file, map) == -1)
		return (0);
	map->map_data = (char **) ft_calloc(map->size[Y] + 1, sizeof(char *));
	while (oget_next_line(map->fd, &line) != 0)
	{
		map->map_data[i] = ft_strndup(line, map->size[X]);
		if (!map->map_data[i])
			return (free(line), ft_dprintf(2, MALLOC_ERR), map_error(map));
		free(line);
		i++;
	}
	if (i != map->size[Y])
		return (ft_dprintf(2, MALLOC_ERR), map_error(map));
	map->map_data[i] = 0;
	return (close(map->fd), 1);
}

int	valid_path(char **map)
{
	
}