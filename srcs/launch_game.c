/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:49 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/20 13:58:15 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	launch_message_screen(t_data *data)
{
	data->mlx = create_window(LEVEL_SIZE, 4);
	data->assets = assets_table(data->mlx.mlx);
	if (!data->assets)
		return (0);
	terminate_level_window(data);
	if (data->win == BYE || data->level == -1)
		return (0);
	return (1);
}


int	launch_game(t_data *data)
{
	char	*level;
 
	while (data->level < 10 && (data->win == RUN || data->win == WIN))
	{
		if (launch_message_screen(data) == 0)
			return (free(level), 0);
		if (data->level < 9)
		{
			init_tmap(&(data->map));
			level = level_char(data->level);
			if (!level)
				return (0);
			if (map_parsing(level, &(data->map)) == 0 
				|| find_path(&(data->map)) == 0)
				return (free(level), 0);
			data->mlx = create_window(data->map.size[X], data->map.size[Y]);
			if (free(level), !data->mlx.mlx_win)
				return (free(level), ft_dprintf(2, WINDOW), 0);
			data->assets = assets_table(data->mlx.mlx);
			if (!data->assets)
				return (free(level), 0);
			terminate_window(data);
			}
	}
	return (free(level), 0);
}
