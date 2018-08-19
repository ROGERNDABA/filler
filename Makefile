# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 15:15:22 by rmdaba            #+#    #+#              #
#    Updated: 2018/08/14 15:35:39 by rmdaba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Roger.filler

INCL = -Iincl -Ilibft/incl

LIB = ./libft

CC = cc -Wall -Wextra -Werror -o $(NAME)

SRC =	output_info.c struct_init.c main.c token_trim.c

all : $(NAME)

$(NAME):
	make -C libft
	$(CC) $(INCL) -L $(LIB) -lft $(addprefix src/, $(SRC))

clean:
	make clean -C $(LIB)

fclean: clean
	make fclean -C $(LIB)
	rm -fr $(NAME)

re: fclean all

.PHONY: clean all fclean
