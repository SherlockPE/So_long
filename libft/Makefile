# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 13:08:07 by flopez-r          #+#    #+#              #
#    Updated: 2024/01/22 18:51:35 by flopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcpy.c ft_memmove.c \
		ft_memcmp.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strnstr.c \
		ft_strmapi.c ft_strtrim.c\
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_substr.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
		printf/ft_pass_hex.c \
		printf/ft_print_memory.c\
		printf/ft_printf.c\
		printf/ft_putchar.c\
		printf/ft_putnbr.c\
		printf/ft_putstr.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c
# BNS_SRCS =	ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c
# 		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)
# BNS_OBJS =	$(BNS_SRCS:.c=.o)

NAME = libft.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
# $(CC) $(FLAGS) $(SRC) -o $(NAME)
	$(AR) -rcs $(NAME) $(OBJ)
	ranlib $(NAME)

# bonus: $(OBJ) $(BNS_OBJS)
# 	ar -rcs $(NAME) $(OBJ) $(BNS_OBJS)
# 	ranlib $(NAME)
clean: 
	rm -f $(OBJ)
# rm -f $(OBJ) $(BNS_OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
