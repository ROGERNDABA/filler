# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 15:15:22 by rmdaba            #+#    #+#              #
#    Updated: 2018/08/27 08:03:29 by rmdaba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = the_ting_goes_skrrr.filler

INCL = -Iincl -Ilibft/incl

LIB = ./libft

CC = cc -o $(NAME)

SRC =	results.c get_map.c main.c algorithm.c get_token.c

all : $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(INCL) -L $(LIB) -lft $(addprefix src/, $(SRC))
	@printf "\n🌸 \e[1;32m[ ✔ ] filler excecutable made\n\e[0m\n"
	@gcc visual/*.c -L $(LIB) -lft $(INCL) -o visualizer

clean:
	@make clean -C $(LIB)

fclean: clean
	@make fclean -C $(LIB)
	@rm -fr $(NAME)

re: fclean all

.PHONY: clean all fclean
