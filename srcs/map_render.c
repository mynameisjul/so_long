/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:18:05 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/19 10:20:16 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render(t_data *data)
{
	int	ok;
	
	ok = render_bottom_margin(data);
	ok = render_border(data);
	ok = render_fix_content(data->mlx, data->map, data->assets);
	ok = render_moving_content(data->mlx, data->map, data->assets);
	ok = render_player(data);
	// if (data->count == 100 && ok == 0)
	// 	ft_dprintf(2, LOAD_ASSETS);
	return (ok);
}