# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwhitloc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 10:20:30 by kwhitloc          #+#    #+#              #
#    Updated: 2017/03/22 16:31:56 by kwhitloc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = get_fillit.c fill_grid.c get_tmp.c make_array.c read_fillit.c

OBJS = get_fillit.o fill_grid.o get_tmp.o make_array.o read_fillit.o

LIB = ./libft
LIBFT = make -C $(LIB)
LIBDESTROY = make -C $(LIB) fclean

all: $(NAME)

$(NAME):
	$(LIBFT)
	$(CC) $(FLAGS) $(SRCS) $(LIB)/libft.a -o $(NAME)

clean:
	$(LIBDESTROY)
	rm -f $(OBJS)

fclean: clean
	$(LIBDESTROY)
	rm -f $(NAME)

re: fclean all
