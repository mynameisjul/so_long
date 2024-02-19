/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:32:54 by julieblaye        #+#    #+#             */
/*   Updated: 2024/02/19 13:44:46 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/so_long.h"

int	main(void)
{
	t_data		data;

	init_tdata(&data);
	while (data.level < 10 && data.win == RUN)
	{
		data.mlx = create_window(LEVEL_SIZE, LEVEL_SIZE);
		data.assets = assets_table(data.mlx.mlx);
		if (!data.assets)
			return (0);
		terminate_level_window(&data);
		if (data.level == -1)
			return (0);
		printf("LEVEL %d\n", data.level);
		if (map_parsing(level_char(data.level), &(data.map)) == 0 
			|| find_path(&(data.map)) == 0)
			return (ft_dprintf(2, "on rentre la\n"), 0);
		data.mlx = create_window(data.map.size[X], data.map.size[Y]);
		if (!data.mlx.mlx_win)
			return (ft_dprintf(2, WINDOW), 0);
		data.assets = assets_table(data.mlx.mlx);
		if (!data.assets)
			return (0);
		terminate_window(&data);
		printf("LEVEL apres %d\n", data.level);
	}
	data.mlx = create_window(LEVEL_SIZE, LEVEL_SIZE);
	data.assets = assets_table(data.mlx.mlx);
	if (!data.assets)
		return (0);
	terminate_level_window(&data);
	return (0);
}
