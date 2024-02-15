/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:32:54 by julieblaye        #+#    #+#             */
/*   Updated: 2024/02/15 17:57:40 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_map 		map;
	t_mlx_data	mlx;
	(void) ac;
	
	init_tmap(&map);
	if (map_parsing(av[1], &map) == 0)
		return (0);
	printf("PATH = %d\n", find_path(&map));
	mlx = create_window(map.size[X], map.size[Y]);
	if (!mlx.mlx_win)
		return (ft_dprintf(2, "FAIL\n"), 0);
	void **table = assets_table(mlx.mlx);
	if (!table)
		return (0);
	//push_tile(mlx, T_BL, 0, 0);
	if (render_border(mlx, map, table) == 0)
		return (0);
	if (render_fix_content(mlx, map, table) == 0)
		return (0);
	if (render_moving_content(mlx, map, table) == 0)
		return (0);
	terminate_window(mlx, &map, table);
	ft_fsplit(map.map_data);
	return (0);
}