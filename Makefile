# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvautour <vautour.brad@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 20:34:48 by bvautour          #+#    #+#              #
#    Updated: 2018/02/05 16:53:00 by bvautour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
FILES = main.c init.c parse.c error.c sort.c compare.c retrieve.c find.c \
		output.c output_dir.c free.c options.c time.c permissions.c spacing.c \
		helpers.c 
SRC = $(addprefix src/, $(FILES))
OBJ = $(addprefix obj/, $(FILES:.c=.o))

LIBFT = -I libs/libft -L libs/libft -lft
LIBS = $(LIBFT)

all: $(NAME)

$(NAME): -lft $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) -I includes $(OBJ) -o $@

obj:
	mkdir obj

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -I libs/libft -I includes -c $< -o $@

-lft:
	$(MAKE) -C libs/libft #re

clean:
	$(MAKE) -C libs/libft clean
	/bin/rm -rf obj

fclean: clean
	$(MAKE) -C libs/libft fclean
	/bin/rm -f $(NAME)

re: fclean all
	
