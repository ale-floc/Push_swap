# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-floc <ale-floc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/13 07:46:27 by ale-floc          #+#    #+#              #
#    Updated: 2015/03/04 11:08:42 by ale-floc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

SRC=main.c algo.c ft_atoi_letter.c func.c operat.c lib.c cut.c ft_putstr_fd.c \
	ft_putchar_fd.c ft_itoa.c

FLAGS= -Wall -Wextra -Werror

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;33mMAKE $(NAME) Please Wait\033[0m\033[K\c"
	@echo "\033[1;33m.\033[0m\033[K\c"
	@sleep 0.5
	@echo "\033[1;33m.\033[0m\033[K\c"
	@sleep 0.5
	@echo "\033[1;33m.\033[0m\033[K"
	@gcc -o $(NAME) $(OBJ)
	@echo "\033[1;32mMAKE $(NAME) OK !\033[0m\033[K"

%.o: %.c
	@gcc $(FLAGS) -ggdb3 -c $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
