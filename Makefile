# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jblaye <jblaye@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 16:04:07 by jblaye            #+#    #+#              #
#    Updated: 2024/02/06 11:09:13 by jblaye           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
TEST_NAME = test_so_long

SRC = srcs/*.c main.c
TEST_SRC = srcs/*.c test.c

HEADERS = -I include/so_long.h -I /usr/include -I mlx_linux -O3 

OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAG = -l Xext -l X11 -lmlx
RM = rm -f

.c.o:
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ 

all:		libft $(NAME)

libft:
			make -C ./libft

$(NAME):	$(OBJ)
			$(CC) $(CLFAGS) $(MLXFLAG) -o $(NAME) $(HEADERS) $(SRC) ./libft/libft.a ./mlx-linux/libmlx_Linux.a ./mlx-linux/libmlx.a 

test:		libft $(TEST_OBJ)
			$(CC) $(CFLAGS) $(MLXFLAG) -o $(TEST_NAME) $(HEADERS) $(TEST_SRC) ./libft/libft.a ./mlx-linux/libmlx_Linux.a ./mlx-linux/libmlx.a

clean:
			rm -f $(OBJ)
			make -C ./libft clean

fclean:		clean
			rm -f $(NAME)

testfclean:
			rm -f $(TEST_OBJ)
			make -C ./libft clean
			rm -f $(TEST_NAME)

re:			fclean all

.PHONY:		all clean fclean re libft