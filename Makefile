# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/17 21:11:30 by nlowe             #+#    #+#              #
#    Updated: 2017/01/25 14:56:44 by nlowe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = src
SRC_NAME = main.c \
			board.c \
			file_validation.c \
			list.c \
			mods.c \
			tetris.c

OBJ_PATH = obj
IFLAGS = -Iinclude
LDFLAGS = -Llibft
LDLIBS = -lft
CC = gcc
CFLAGS  = -Werror -Wall -Wextra
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $^

$(LIBFT):
	@make -C ./libft/

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONYL: all, clean, fclean, re
