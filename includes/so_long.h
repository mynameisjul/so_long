/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:21:19 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/06 10:52:07 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "./libft/libft.h"
# include "./mlx-linux/mlx.h"

# define WIDTH 1920
# define HEIGHT 1000

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
}				t_coord;

typedef struct s_vec2
{
	double	x;
	double	y;
}				t_vec2;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/// GRAPHIC FUNCTIONS
int		create_window(void);
int		push_image(void *mlx, void *mlx_win);
void	free_all(void *mlx, void *mlx_win, t_img *img);
void	terminate_window(void *mlx, void *mlx_win, t_img *img);


#endif