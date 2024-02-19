/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:32:54 by julieblaye        #+#    #+#             */
/*   Updated: 2024/02/19 15:31:00 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/so_long.h"

int	main(void)
{
	t_data		data;

	init_tdata(&data);
	while (data.level < 10 && (data.win == RUN || data.win == WIN))
	{
		data.mlx = create_window(LEVEL_SIZE, 4);
		data.assets = assets_table(data.mlx.mlx);
		if (!data.assets)
			return (0);
		terminate_level_window(&data);
		if (data.win == BYE)
			return (0);
		if (data.level == -1)
			return (0);
		init_tmap(&(data.map));
		if (map_parsing(level_char(data.level), &(data.map)) == 0 
			|| find_path(&(data.map)) == 0)
			return (0);
		data.mlx = create_window(data.map.size[X], data.map.size[Y]);
		if (!data.mlx.mlx_win)
			return (ft_dprintf(2, WINDOW), 0);
		data.assets = assets_table(data.mlx.mlx);
		if (!data.assets)
			return (0);
		terminate_window(&data);
		data.steps = 0;
	}
	if (data.win == BYE)
		return (0);
	// data.mlx = create_window(LEVEL_SIZE, 3);
	// data.assets = assets_table(data.mlx.mlx);
	// if (!data.assets)
	// 	return (0);
	// terminate_level_window(&data);
	return (0);
}
