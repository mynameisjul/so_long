/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:32:54 by julieblaye        #+#    #+#             */
/*   Updated: 2024/02/14 16:31:33 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_map map;
	void	*mlx;
	(void) ac;
	
	init_tmap(&map);
	if (map_parsing(av[1], &map) == 0)
		return (0);
	printf("%d\n", find_path(&map));
	mlx = create_window(map.size[X], map.size[Y]);
	push_tile(mlx, T_BL, 0, 0);
	// if (render_border(mlx, map) == 0)
	// 	return (0);
	ft_fsplit(map.map_data);
	return (0);
}