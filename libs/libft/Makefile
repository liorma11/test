# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvautour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/24 14:47:23 by bvautour          #+#    #+#              #
#    Updated: 2018/01/18 11:25:50 by bvautour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a 

AR		= ar

CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror -I .
 
PART1	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c	ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c 
	   		
PART2	= ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

BONUS	= ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		  ft_lstmap.c

EXTRA	= ft_numlen.c ft_strrev.c ft_isspace.c ft_wordcount.c ft_puterr.c \
		  get_next_line.c ft_puterrv.c

FILES 	= $(PART1) $(PART2) $(BONUS) $(EXTRA)

SRC		= $(addprefix src/, $(FILES))
OBJ 	= $(addprefix obj/, $(FILES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)

clean:
	/bin/rm -rf obj

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

obj:
	mkdir obj/

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@
