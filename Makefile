# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 16:04:07 by jblaye            #+#    #+#              #
#    Updated: 2024/02/21 18:33:46 by jblaye           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
TEST_NAME = test_so_long

SRC = srcs/assets_loading.c srcs/map_parsing.c srcs/assets_utils.c \
		srcs/enemy_movements.c srcs/ennemy_movements_utils.c srcs/map_render_enemy.c \
 		srcs/map_render_player.c srcs/player_movements.c srcs/player_movements_utils.c \
		srcs/ft_hook.c srcs/window_management.c srcs/launch_game.c srcs/level_management.c \
		srcs/map_render_utils.c srcs/map_render.c \
        srcs/map_check.c srcs/valid_path.c srcs/map_check_utils.c \
 		main.c

TEST_SRC =  srcs/assets_loading.c srcs/map_parsing.c srcs/assets_utils.c \
		srcs/enemy_movements.c srcs/ennemy_movements_utils.c srcs/map_render_enemy.c \
 		srcs/map_render_player.c srcs/player_movements.c srcs/player_movements_utils.c \
		srcs/ft_hook.c srcs/window_management.c srcs/launch_game.c srcs/level_management.c \
		srcs/map_render_utils.c srcs/map_render.c \
        srcs/map_check.c srcs/valid_path.c srcs/map_check_utils.c \
		test.c

HEADERS = -I /includes -I /usr/includes -I mlx-linux -O3 

OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror
MLXFLAG = -Lmlx-linux -lmlx_Linux -lXext -lX11 -lm
RM = rm -f

TEST_MACRO = -D BONUS=1

.c.o:
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ 

all:		libft $(NAME)

libft:
			make -C ./libft

$(NAME):	$(OBJ)
			$(CC) $(CLFAGS) $(HEADERS) $(SRC) ./libft/libft.a ./mlx-linux/libmlx_Linux.a ./mlx-linux/libmlx.a $(MLXFLAG) -o $(NAME)

bonus:		libft $(OBJ)
			$(CC) $(CFLAGS) $(HEADERS) $(TEST_MACRO) $(SRC) ./libft/libft.a ./mlx-linux/libmlx_Linux.a ./mlx-linux/libmlx.a $(MLXFLAG) -o $(NAME)

test:		libft $(TEST_OBJ)
			$(CC) $(CFLAGS) $(HEADERS) $(TEST_MACRO) $(TEST_SRC) ./libft/libft.a ./mlx-linux/libmlx_Linux.a ./mlx-linux/libmlx.a $(MLXFLAG) -o $(TEST_NAME)

clean:
			rm -f $(OBJ)
			make -C ./libft clean

fclean:		clean
			make -C ./libft fclean
			rm -f $(NAME)

testfclean:
			rm -f $(TEST_OBJ)
			make -C ./libft fclean
			rm -f $(TEST_NAME)

re:			fclean all

.PHONY:		all clean fclean re libft