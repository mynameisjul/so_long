/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:31:49 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/13 14:26:57 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	map_check(t_map *map)
{
	t_read	read;
	int		valid_last_line;

	read.count = 0;
	valid_last_line = 0;
	ognl_nb(map->fd, &read);
	if (!read.line)
		return (close(map->fd), 0);
	map->size[X] = ft_strlen(read.line) - 1;
	map->size[Y] = 1;
	map->isvalid = valid_wall_line(*map, read.line, 0);
	if (map->isvalid == 0)
		return (close(map->fd), free(read.line), map->isvalid);
	while (free(read.line), ognl_nb(map->fd, &read) != 0 && map->size[Y] < 33)
	{
		map->isvalid = valid_line(map, read);
		if (map->isvalid == 0)
			return (close(map->fd), free(read.line), map->isvalid);
		map->size[Y]++;
		valid_last_line = valid_wall_line(*map, read.line, 1);
	}
	if (valid_last_line == 0)
		return (close(map->fd), 0);
	return (close(map->fd), map->isvalid);
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
	if (map_check(map) == 0 ||  map->nb_coins < 1)
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
