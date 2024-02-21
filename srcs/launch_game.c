/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:49 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/21 18:15:12 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	launch_message_screen(t_data *data)
{
	if (create_win(data, LEVEL_SIZE, 4) == 0)
		return (0);
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

	while (data->level < 6 && (data->win == RUN || data->win == WIN))
	{
		if (launch_message_screen(data) == 0)
			return (0);
		if (data->level < 6)
		{
			init_tmap(&(data->map));
			level = level_char(data->level);
			if (!level)
				return (0);
			if (map_parsing(level, &(data->map)) == 0
				|| find_path(&(data->map)) == 0
				|| create_win(data, data->map.size[X], data->map.size[Y]) == 0)
				return (free(level), 0);
			data->assets = assets_table(data->mlx.mlx);
			if (!data->assets)
				return (free(level), 0);
			free(level);
			terminate_window(data);
		}
	}
	return (0);
}
