/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:20:52 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/19 12:36:17 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(void)
{
	t_data		data;
	
	init_tdata(&data);
	while (data.level < 10)
	{
		data.mlx = create_window(LEVEL_SIZE, LEVEL_SIZE);
		data.assets = assets_table(data.mlx.mlx);
		if (!data.assets)
			return (0);
		terminate_level_window(&data);
		if (map_parsing(level_char(data.level), &(data.map)) == 0 || find_path(&(data.map)) == 0)
			return (0);
		data.mlx = create_window(data.map.size[X], data.map.size[Y]);
		if (!data.mlx.mlx_win)
			return (ft_dprintf(2, WINDOW), 0);
		data.assets = assets_table(data.mlx.mlx);
		if (!data.assets)
			return (0);
		terminate_window(&data);
		data.level++;
	}
	data.mlx = create_window(LEVEL_SIZE, LEVEL_SIZE);
	data.assets = assets_table(data.mlx.mlx);
	if (!data.assets)
		return (0);
	terminate_level_window(&data);
	return (0);
	return (0);
}
