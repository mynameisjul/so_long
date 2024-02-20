/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:45:30 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/20 14:08:18 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	valid_line(t_map *map, t_read read)
{
	int	i;

	i = 0;
	if (read.line)
	{
		while (read.line[i] != '\n' && read.line[i] != 0)
		{
			if (isvalidmapchar(read.line[i]) == 0)
				return (0);
			if (read.line[i] == PLAYER || read.line[i] == EXIT)
			{
				if (fetch_element_coordinates(map, read, i) == 0)
					return (0);
			}
			if (read.line[i] == COIN)
				map->nb_coins++;
			if (read.line[i] == ENEMIES || read.line[i] == LENEMIES)
				map->enemy++;
			i++;
		}
		if (i == map->size[X] && read.line[0] == WALL 
			&& read.line[i - 1] == WALL)
			return (1);
	}
	return (0);
}
