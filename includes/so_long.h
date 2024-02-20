/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:21:19 by jblaye            #+#    #+#             */
/*   Updated: 2024/02/20 14:07:07 by jblaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx-linux/mlx.h"
# include "so_long_defines.h"

typedef struct s_map
{
	char **map_data;
	int fd;
	int isvalid;
	int size[2];
	int nb_coins;
	int player[2];
	int exit[2];
	int	enemy;
}				t_map;

typedef struct s_mlx_data
{
	void *mlx;
	void *mlx_win;
}				t_mlx_data;

typedef struct s_img
{
	void *img_ptr;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}				t_img;

typedef struct s_data
{
	t_mlx_data mlx;
	t_map map;
	void **assets;
	int count;
	int	steps;
	int	level;
	int	win;
	int enemy_speed;
}				t_data;

/////////////////////////////////
/////// LEVEL MANAGEMENT ////////
/////////////////////////////////

int			render_level_window(t_data	*data);
char		*level_char(int	level);
void		terminate_level_window(t_data *data);
int			ft_level_hook(int keycode, t_data *data);
int			launch_message_screen(t_data *data);
int			launch_game(t_data *data);

/////////////////////////////////
/////////// PARSING /////////////
/////////////////////////////////

/// MAP CHECK UTILS
int			isvalidmapchar(char c);

/// MAP PARSING
int			fetch_element_coordinates(t_map *map, t_read read, int i);
t_map		init_tmap(t_map *map);
t_data		init_tdata(t_data *data);
int			valid_wall_line(t_map map, char *line, int last);
int			valid_line(t_map *map, t_read read);
int			map_error(t_map *map);
int			open_map(char *file_name, t_map *map);
int			map_check(t_map *map);
int			map_parsing(char *file, t_map *map);

/// PATH FINDING
int			recurs_path_find(char **m, t_map *cpmap, t_map map, int x, int y);
int			find_path(t_map *map);

/////////////////////////////////
/////// GRAPHIC FUNCTIONS ///////
/////////////////////////////////

/// WINDOW MANAGEMENT
t_mlx_data	create_window(int x, int y);
void		free_all(t_data *data);
void		terminate_window(t_data *data);
int			custom_loop_end(t_data *data);

/// ASSETS LOADING
void		*xpm_to_image(void *mlx, char *relative_path);
void		free_non_null(void ***table, int size);
void		**assets_table(void *mlx);

/// MAP RENDER
int			push_tile(t_mlx_data mlx, void *asset, int x_coord, int y_coord);
int			render_bottom_margin(t_data *data);
int			render_border(t_data *data);
int			render_fix_content(t_mlx_data mlx, t_map map, void **assets);
int			render_player(t_data *data);
int			render_moving_content(t_mlx_data mlx, t_map map, void **assets);
int			render(t_data *data);
int			render_counts(t_data *data);

/// PLAYER MOVES MANAGEMENT
int			ft_hook(int keycode, t_data *data);
void		left_player_update(t_data *data, int x, int y);
void		right_player_update(t_data *data, int x, int y);
void		whole_map_update(t_data *data, int x, int y);
int			player_up(t_data *data);
int			player_down(t_data *data);
int			player_left(t_data *data);
int			player_right(t_data *data);

/////////////////////////////////
/////// ENEMY MANAGEMENT ////////
/////////////////////////////////

int			render_enemies(t_data *data);
int			move_single_enemy_up(t_data *data, int x, int y);
int			move_single_enemy_down(t_data *data, int x, int y);
int			move_single_enemy_left(t_data *data, int x, int y);
int			move_single_enemy_right(t_data *data, int x, int y);
int			move_single_enemy(t_data *data, int x, int y);
int			move_enemies(t_data *data);

#endif