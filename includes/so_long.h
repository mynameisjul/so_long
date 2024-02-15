/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:21:19 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/15 17:52:25 by jblaye           ###   ########.fr       */
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
	int		isvalid;
	int		size[2];
	int		nb_coins;
	int		player[2];
	int		exit[2];
	int		enemies;
}				t_map;

typedef struct s_mlx_data {
	void	*mlx;
	void	*mlx_win;
}				t_mlx_data;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data {
	t_mlx_data	data;
	t_map		*map;
}				t_data;

/// MAP CHECK UTILS
int			isvalidmapchar(char c);

/// MAP PARSING
int			fetch_element_coordinates(t_map *map, t_read read, int i);
t_map		init_tmap(t_map *map);
int			valid_wall_line(t_map map, char *line, int last);
int			valid_line(t_map *map, t_read read);
int			map_error(t_map *map);
int			open_map(char *file_name, t_map *map);
int			map_check(t_map *map);
int			map_parsing(char *file, t_map *map);

/// PATH FINDING
int 		recurs_path_find(char **m, t_map *cpmap, t_map map, int x, int y);
int			find_path(t_map *map);

/// GRAPHIC FUNCTIONS ///

/// WINDOW MANAGEMENT AND GRAPHIC INITIALISATION
t_mlx_data	create_window(int x, int y);
int 		push_tile(t_mlx_data mlx, void *asset, int x_coord, int y_coord);
void		*xpm_to_image(void *mlx, char *relative_path);
int			render_border(t_mlx_data mlx, t_map map, void **assets);
int			render_fix_content(t_mlx_data mlx, t_map map, void **assets);
int			render_moving_content(t_mlx_data mlx, t_map map, void **assets);
void		free_non_null(void ***table, int size);
void		**assets_table(void *mlx);
void		free_all(void *mlx, void *mlx_win, void **assets);
void		terminate_window(t_mlx_data mlx, t_map *map, void **assets);

/// PLAYER MOVES MANAGEMENT
int			ft_hook(int	keycode, t_map *map);

#endif