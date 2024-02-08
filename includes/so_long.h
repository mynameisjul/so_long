/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:21:19 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/08 12:35:59 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx-linux/mlx.h"
# include "so_long_defines.h"

typedef 

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/// MAP PARSING
int		open_map(char *file_name);

/// GRAPHIC FUNCTIONS
int		create_window(void);
int		push_image(void *mlx, void *mlx_win);
void	free_all(void *mlx, void *mlx_win, t_img *img);
void	terminate_window(void *mlx, void *mlx_win, t_img *img);


#endif