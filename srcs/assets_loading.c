/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_loading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:01:19 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/15 17:22:50 by jblaye           ###   ########.fr       */
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

int	charge_base(void *mlx, void ***table)
{
	int	i;

	i = 0;
	table[0][T_SPACE] = xpm_to_image(mlx, "assets/space.xpm");
	table[0][T_TL] = xpm_to_image(mlx, "assets/top_left.xpm");
	table[0][T_TR] = xpm_to_image(mlx, "assets/top_right.xpm");
	table[0][T_BL] = xpm_to_image(mlx, "assets/bott_left.xpm");
	table[0][T_BR] = xpm_to_image(mlx, "assets/bott_right.xpm");
	table[0][T_TOP] = xpm_to_image(mlx, "assets/top.xpm");
	table[0][T_BOTT] = xpm_to_image(mlx, "assets/bott.xpm");
	table[0][T_RIGHT] = xpm_to_image(mlx, "assets/right.xpm");
	table[0][T_LEFT] = xpm_to_image(mlx, "assets/left.xpm");
	while (i <= T_RIGHT)
	{
		if (table[0][i] == 0)
			return (ft_dprintf(2, LOAD_ASSETS), free_non_null(table, 21), 0);
		i++;
	}
	return (1);
}

int	charge_assets(void *mlx, void ***table)
{
	int	i;

	i = T_COIN;
	table[0][T_COIN] = xpm_to_image(mlx, "assets/coin.xpm");
	table[0][T_COLLEC_COIN] = xpm_to_image(mlx, "assets/collected_coin.xpm");
	table[0][T_WALL] = xpm_to_image(mlx, "assets/obstacle.xpm");
	table[0][T_EXIT] = xpm_to_image(mlx, "assets/closed_exit.xpm");
	table[0][T_OPEN_EXIT] = xpm_to_image(mlx, "assets/open_exit.xpm");
	table[0][T_PLAYER_COIN] = xpm_to_image(mlx, "assets/player_on_coin.xpm");
	table[0][T_PLAYER] = xpm_to_image(mlx, "assets/player.xpm");
	table[0][T_P1] = xpm_to_image(mlx, "assets/player_1.xpm");
	table[0][T_P2] = xpm_to_image(mlx, "assets/player_2.xpm");
	table[0][T_P3] = xpm_to_image(mlx, "assets/player_3.xpm");
	table[0][T_ENEMY] = xpm_to_image(mlx, "assets/enemy.xpm");
	while (i < NB_ASSETS)
	{
		if (table[0][i] == NULL)
			return (ft_dprintf(2, LOAD_ASSETS), free_non_null(table, 21), 0);
		i++;
	}
	return (1);
}

void	**assets_table(void *mlx)
{
	void	**table;

	table = (void **) ft_calloc(22, sizeof(void *));
	if (!table)
		return (ft_dprintf(2, MALLOC_ERR), NULL);
	if (charge_base(mlx, &table) == 0 || charge_assets(mlx, &table) == 0)
		return (free(table), NULL);
	return (table);
}
