# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/24 13:57:10 by aeclipso          #+#    #+#              #
#    Updated: 2020/10/25 15:23:38 by aeclipso         ###   ########.fr        #
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

LIBFT=libft-printf

OBJ=$(SRC:.c=.o)

FLAGS=-Wall -Wextra -Werror

FLAGS+= -I include

FLAGS+= -I $(LIBFT)/include

NAME=aeclipso.filler

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	FOLDER=ressources-linux/champions/
else ifeq ($(UNAME_S),Darwin)
	FOLDER=resources/players/
endif

all: $(NAME)

libft.a :
	@$(MAKE) --no-print-directory -C $(LIBFT) all

$(NAME): $(OBJ) | libft.a
	@gcc -o $@ $^ -L $(LIBFT) -lft
	@cp aeclipso.filler $(FOLDER)

$(OBJ): %.o: %.c
		@gcc $(FLAGS) -I $(INC) -MD -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@$(MAKE) --no-print-directory -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(FOLDER)$(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean

re: fclean all
