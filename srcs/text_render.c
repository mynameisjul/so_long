/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:12:05 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/21 17:14:48 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_text(t_data *data, int y, char **text)
{
	return (mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, TILE * 2, y,
			0x0, text));
}
