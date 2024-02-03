# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 15:12:06 by flopez-r          #+#    #+#              #
#    Updated: 2024/02/03 13:40:32 by flopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

SRC :=	src/main.c \
		src/utils.c \
		src/map_check.c \
		src/map_utils.c \
		src/map_valid_exit.c \
		src/grafic_utils.c \
		src/grafic_start.c \
		src/animations.c
OBJ := $(SRC:.c=.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror -I includes
INCLUDE_FLAG = -I includes
# OBJ = $(patsubst $(SRC), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
