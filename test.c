/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:32:54 by julieblaye        #+#    #+#             */
/*   Updated: 2024/02/16 18:11:43 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_data		data;
	(void) ac;
	
	init_tmap(&(data.map));
	data.count = 0;
	if (map_parsing(av[1], &(data.map)) == 0 || find_path(&(data.map)) == 0)
		return (0);
	data.mlx = create_window(data.map.size[X], data.map.size[Y]);
	if (!data.mlx.mlx_win)
		return (ft_dprintf(2, "FAIL\n"), 0);
	data.assets = assets_table(data.mlx.mlx);
	if (!data.assets)
		return (0);
	//push_tile(mlx, T_BL, 0, 0);
	// if (render(&data) == 0)
	// 	return (0);
	terminate_window(&data);
	ft_fsplit(data.map.map_data);
	return (0);
}