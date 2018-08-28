# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmdaba <rmdaba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/21 22:58:58 by rmdaba            #+#    #+#              #
#    Updated: 2018/08/27 08:00:35 by rmdaba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BUILD is initially undefined
ifndef BUILD

# max equals 256 x's
sixteen := x x x x x x x x x x x x x x x x
MAX := $(foreach x,$(sixteen),$(sixteen))

# T estimates how many targets we are building by replacing BUILD with a special string
T := $(shell $(MAKE) -nrRf $(firstword $(MAKEFILE_LIST)) $(MAKECMDGOALS) \
            BUILD="COUNTTHIS" | grep -c "COUNTTHIS")

# N is the number of pending targets in base 1, well in fact, base x :-)
N := $(wordlist 1,$T,$(MAX))

# auto-decrementing counter that returns the number of pending targets in base 10
counter = $(words $N)$(eval N := $(wordlist 2,$(words $N),$N))

# BUILD is now defined to show the progress, this also avoids redefining T in loop
BUILD = @printf "\e[38;5;82m%s\e[0m" $(counter)
endif

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

INC = -I ./incl/

FILES =	buffer.c ft_arrsize.c ft_atoi.c \
		ft_bzero.c ft_check_fmt.c ft_dlstadd.c ft_dlstaddback.c \
		ft_dlstgethead.c ft_dlstgettail.c ft_dlstnew.c ft_dlstremoveif.c \
		ft_dlstremovenode.c ft_dlstsize.c ft_find_flag.c ft_getchar.c ft_isalnum.c \
		ft_isalpha.c ft_isascii.c ft_isblank.c ft_iscntrl.c ft_isdigit.c \
		ft_isgraph.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c \
		ft_isxdigit.c ft_itoa.c ft_itoa_base.c ft_lstadd.c ft_lstdel.c \
		ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memdup.c ft_memjoin.c ft_memmove.c ft_memset.c ft_rsqrt.c\
		ft_print_error.c ft_printf.c ft_printf_base.c ft_printf_base_tools.c \
		ft_printf_nbr.c ft_printf_nbr_tools.c ft_printf_putchar.c ft_printf_string.c \
		ft_printf_stringuni.c ft_printf_stringuni2.c ft_putchar.c ft_putchar_fd.c \
		ft_putchar_uni.c ft_putchar_uni2.c ft_putendl.c ft_putendl_fd.c \
		ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		ft_str_is_alpha.c ft_str_is_lowercase.c ft_str_is_numeric.c \
		ft_str_is_printable.c ft_str_is_uppercase.c ft_strbetween.c \
		ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strcspn.c ft_strdel.c ft_strdup.c ft_strequ.c ft_strindexchr.c \
		ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
		ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strpbrk.c ft_strrchr.c \
		ft_strsplit.c ft_strspn.c ft_strstr.c ft_strsub.c ft_strtok.c \
		ft_strtrim.c ft_tolower.c ft_toupper.c ft_type.c get_next_line.c \

SRC = $(addprefix srcs/, $(FILES))

OBJ = 	$(addprefix obj/, $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\n\e[1;33m----------------------------------------\n\e[0m"
	@printf "\n🌸 \e[1;32m[ ✔ ] Libft library made\n\e[0m\n"

clean:
	@rm -rf obj
	@printf "\n🌸 \e[1;31m[ ✔ ] Object files removed\n\e[0m\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "🌸 \e[1;33m[ ✔ ] libft library removed\n\e[0m\n"

re: fclean all

obj:
	@mkdir obj/

obj/%.o: srcs/%.c obj
	@printf "\n\e[1;33m----------------------------------------\n|"
	@gcc $(FLAGS) -c $(INC) $< -o $@
	@printf "\e[38;5;57m %-28s \e[1;33m|\e[0m" $<
	@printf " \e[48;5;201m\e[92m  ✔  \e[0m \e[1;33m|\e[0m  "
	$(BUILD)
.PHONY: all, clean, fclean, re
