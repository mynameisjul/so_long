/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:21:19 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/12 16:05:15 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx-linux/mlx.h"
# include "so_long_defines.h"

typedef struct s_map {
	char	**map_data;
	int		fd;
	int		size[2];
	int		nb_coins;
	int		player[2];
	int		exit[2];
	int		enemies;
}				t_map;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/// MAP PARSING
t_map	init_tmap(t_map *map);
int		valid_wall_line(t_map map, char *line, int last);
int		valid_line(t_map *map, char	*line);
int		map_error(t_map *map);
int		open_map(char *file_name, t_map *map);
int		map_check(t_map *map);
int		map_parsing(char *file, t_map *map);

/// GRAPHIC FUNCTIONS
int		create_window(void);
int		push_image(void *mlx, void *mlx_win);
void	free_all(void *mlx, void *mlx_win, t_img *img);
void	terminate_window(void *mlx, void *mlx_win, t_img *img);


#endif