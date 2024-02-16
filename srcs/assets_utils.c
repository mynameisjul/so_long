/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:27:13 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/16 18:31:29 by jblaye           ###   ########.fr       */
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
		return (ft_dprintf(2, LOAD_ASSETS), NULL);
	return (img);
}

void	free_non_null(void ***table, int size)
{
	while (size > 0)
	{
		if (table[0][size - 1] != NULL)
			free(table[0][size - 1]);
		size--;
	}
}
