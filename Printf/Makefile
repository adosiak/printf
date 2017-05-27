# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwhitloc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 10:20:30 by kwhitloc          #+#    #+#              #
#    Updated: 2017/05/26 17:28:27 by adosiak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

CC = gcc

FLAGS = 

SRCS = main.c parse.c work_var.c
OBJS = main.o parse.o work_var.o

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
