# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.txt                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 12:23:06 by rmurdoch          #+#    #+#              #
#    Updated: 2018/01/09 12:23:11 by rmurdoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= filler
FILES 	= main.c\
			get_all_inputs.c\
			processing.c
SRC 	= $(addprefix src/, $(FILES))
CC 		= gcc
FLAGS 	= -Wall -Wextra -Werror
LINK	= -L libft -lft
INCLUDE	= -I header/filler.h -I libft/libft.h

all: $(NAME)

$(NAME):  lib
	$(CC) $(FLAGS) $(SRC) libft/*.c $(INCLUDE) $(LINK) -o $(NAME)

clean:
	@rm -rf .obj/
	@make clean -C libft

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft

re: fclean all

lib:
	@make -C libft

relib:
	@make re -C libft