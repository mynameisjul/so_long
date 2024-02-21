/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_loading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:01:19 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/21 15:03:48 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	charge_base(void *mlx, void ***table)
{
	table[0][T_SPACE] = xpm_to_image(mlx, "assets/space.xpm");
	table[0][T_TL] = xpm_to_image(mlx, "assets/top_left.xpm");
	table[0][T_TR] = xpm_to_image(mlx, "assets/top_right.xpm");
	table[0][T_BL] = xpm_to_image(mlx, "assets/bott_left.xpm");
	table[0][T_BR] = xpm_to_image(mlx, "assets/bott_right.xpm");
	table[0][T_TOP] = xpm_to_image(mlx, "assets/top.xpm");
	table[0][T_BOTT] = xpm_to_image(mlx, "assets/bott.xpm");
	table[0][T_RIGHT] = xpm_to_image(mlx, "assets/right.xpm");
	table[0][T_LEFT] = xpm_to_image(mlx, "assets/left.xpm");
	table[0][T_LOWBORD] = xpm_to_image(mlx, "assets/lower_border.xpm");
}

void	charge_player_assets(void *mlx, void ***table)
{
	table[0][T_PLAYER] = xpm_to_image(mlx, "assets/player.xpm");
	table[0][T_P1] = xpm_to_image(mlx, "assets/player_1.xpm");
	table[0][T_P2] = xpm_to_image(mlx, "assets/player_2.xpm");
	table[0][T_P3] = xpm_to_image(mlx, "assets/player_3.xpm");
	table[0][T_LPLAYER] = xpm_to_image(mlx, "assets/lplayer.xpm");
	table[0][T_LP1] = xpm_to_image(mlx, "assets/lplayer_1.xpm");
	table[0][T_LP2] = xpm_to_image(mlx, "assets/lplayer_2.xpm");
	table[0][T_LP3] = xpm_to_image(mlx, "assets/lplayer_3.xpm");
	table[0][T_PLAYER_COIN] = xpm_to_image(mlx, "assets/player_on_coin.xpm");
	table[0][T_LPLAYER_COIN] = xpm_to_image(mlx, "assets/lplayer_on_coin.xpm");
}

void	charge_assets(void *mlx, void ***table)
{
	table[0][T_COIN] = xpm_to_image(mlx, "assets/coin.xpm");
	table[0][T_COLLEC_COIN] = xpm_to_image(mlx, "assets/collected_coin.xpm");
	table[0][T_WALL] = xpm_to_image(mlx, "assets/obstacle.xpm");
	table[0][T_EXIT] = xpm_to_image(mlx, "assets/closed_exit.xpm");
	table[0][T_OPEN_EXIT] = xpm_to_image(mlx, "assets/open_exit.xpm");
	table[0][T_ENEMY] = xpm_to_image(mlx, "assets/enemy.xpm");
}

void	charge_enemy(void *mlx, void ***table)
{
	table[0][T_E1] = xpm_to_image(mlx, "assets/enemy_1.xpm");
	table[0][T_E2] = xpm_to_image(mlx, "assets/enemy_2.xpm");
	table[0][T_E3] = xpm_to_image(mlx, "assets/enemy_3.xpm");
	table[0][T_E4] = xpm_to_image(mlx, "assets/enemy_4.xpm");
	table[0][T_LE1] = xpm_to_image(mlx, "assets/lenemy_1.xpm");
	table[0][T_LE2] = xpm_to_image(mlx, "assets/lenemy_2.xpm");
	table[0][T_LE3] = xpm_to_image(mlx, "assets/lenemy_3.xpm");
	table[0][T_LE4] = xpm_to_image(mlx, "assets/lenemy_4.xpm");
}

void	**assets_table(void *mlx)
{
	void	**table;
	int		i;

	i = 0;
	table = (void **) ft_calloc(NB_ASSETS + 1, sizeof(void *));
	if (!table)
		return (ft_dprintf(2, MALLOC_ERR), NULL);
	charge_base(mlx, &table);
	charge_assets(mlx, &table);
	charge_player_assets(mlx, &table);
	charge_enemy(mlx, &table);
	while (i < NB_ASSETS)
	{
		if (table[i] == NULL)
		{
			ft_dprintf(2, LOAD_ASSETS);
			free_non_null(&table, NB_ASSETS);
			free(table);
			return (table);
		}
		i++;
	}
	return (table);
}
