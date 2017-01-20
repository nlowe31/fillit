# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/17 21:11:30 by nlowe             #+#    #+#              #
#    Updated: 2017/01/20 17:48:19 by nlowe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = main.c board.c file_validation.c list.c mods.c tetris.c
O_FILES = $(SRC:.c=.o)
FLAGS  = -Werror -Wall -Wextra -L./libft -lft

all: $(NAME)

$(NAME):
	gcc $(SRC) -c
	gcc $(FLAGS) $(O_FILES) -o $(NAME)

clean:
	rm -f $(O_FILES)

then_clean: re clean

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
