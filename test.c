/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:32:54 by julieblaye        #+#    #+#             */
/*   Updated: 2024/02/21 14:41:30 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_data		data;

	init_tdata(&data);
	if (ac == 2)
	{
		data.mlx = create_window(LEVEL_SIZE, 4);
		data.assets = assets_table(data.mlx.mlx);
		if (!data.assets)
			return (0);
		data.level = -2;
		terminate_level_window(&data);
		if (data.win == BYE || data.level == -2)
			return (0);
		init_tmap(&(data.map));
		if (map_parsing(av[1], &(data.map)) == 0 || find_path(&(data.map)) == 0)
			return (0);
		data.mlx = create_window(data.map.size[X], data.map.size[Y]);
		if (!data.mlx.mlx_win)
			return (ft_dprintf(2, WINDOW), 0);
		data.assets = assets_table(data.mlx.mlx);
		if (!data.assets)
			return (0);
		return (terminate_window(&data), 0);
	}
	return (launch_game(&data));
}
