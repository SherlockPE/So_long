# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 15:12:06 by flopez-r          #+#    #+#              #
#    Updated: 2024/01/17 15:57:32 by flopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

SRC := src/main.c
OBJ := $(SRC:.c=.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror -I includes -g3
INCLUDE_FLAG = -I includes
# OBJ = $(patsubst $(SRC), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME) 

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
