# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/24 13:57:10 by aeclipso          #+#    #+#              #
#    Updated: 2020/10/24 14:52:15 by aeclipso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=free.c\
	heat_map.c\
	main.c\
	read_map.c\
	read_piece.c\
	read_player.c\
	set_piece.c\
	solver.c

INC=include

LIBFT=libft-printf

OBJ=$(SRC:.c=.o)

FLAGS=-Wall -Wextra -Werror

NAME=aeclipso.filler

all: $(NAME)

libft.a :
	@$(MAKE) -C $(LIBFT) all

$(NAME): $(OBJ)
	gcc -o $@ $^ -L $(LIBFT) -lft

$(OBJ): %.o: %.c
		@gcc $(FLAGS) -I $(INC) -MD $(SRC) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
