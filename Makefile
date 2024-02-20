# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 16:04:07 by jblaye            #+#    #+#              #
#    Updated: 2024/02/20 12:04:28 by jblaye           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
TEST_NAME = test_so_long

SRC = srcs/*.c main.c
TEST_SRC = srcs/*.c test.c

HEADERS = -I /includes -I /usr/includes -I mlx-linux -O3 

OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror
MLXFLAG = -Lmlx-linux -lmlx_Linux -lXext -lX11 -lm
RM = rm -f

.c.o:
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ 

all:		libft $(NAME)

libft:
			make -C ./libft

$(NAME):	$(OBJ)
			$(CC) $(CLFAGS) $(HEADERS) $(SRC) ./libft/libft.a ./mlx-linux/libmlx_Linux.a ./mlx-linux/libmlx.a $(MLXFLAG) -o $(NAME)

bonus:		# objs et libft #
# ajouter BONUS=1

test:		libft $(TEST_OBJ)
			$(CC) $(CFLAGS) $(HEADERS) $(TEST_SRC) ./libft/libft.a ./mlx-linux/libmlx_Linux.a ./mlx-linux/libmlx.a $(MLXFLAG) -o $(TEST_NAME)

clean:
			rm -f $(OBJ)
			make -C ./libft clean

fclean:		clean
			rm -f $(NAME)

testfclean:
			rm -f $(TEST_OBJ)
			make -C ./libft fclean
			rm -f $(TEST_NAME)

re:			fclean all

.PHONY:		all clean fclean re libft