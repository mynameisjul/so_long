/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:27:13 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/23 17:56:55 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*xpm_to_image(void *mlx, char *relative_path)
{
	int		size;
	int		size2;
	void	*img;

	size = TILE;
	size2 = TILE;
	img = mlx_xpm_file_to_image(mlx, relative_path, &size, &size2);
	if (img == 0)
		return (NULL);
	return (img);
}

// void	free_non_null(void **table, int size, t_data *data)
// {
// 	while (size > 0)
// 	{
// 		if (table[size - 1] != NULL)
// 		{
// 			mlx_destroy_image(data->mlx.mlx, table[size - 1]);
// 		}
// 		size--;
// 	}
// }
