/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:20:52 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/23 17:56:05 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	t_data		data;

	if (ac != 2 && BONUS == 0)
		return (ft_dprintf(2, NOT_OPEN), 0);
	if (init_tdata(&data), ac == 2)
	{
		if (create_win(&data, LEVEL_SIZE, 4) == 0)
			return (0);
		if (!assets_table(data.mlx.mlx, &data))
			return (free_all(&data), 0);
		data.level = -2;
		terminate_level_window(&data);
		if (data.win == BYE || data.level == -2)
			return (0);
		init_tmap(&(data.map));
		if (map_parsing(av[1], &(data.map)) == 0 || find_path(&(data.map)) == 0
			|| create_win(&data, data.map.size[X], data.map.size[Y]) == 0)
			return (0);
		if (!assets_table(data.mlx.mlx, &data))
			return (0);
		return (terminate_window(&data), 0);
	}
	return (launch_game(&data));
}
