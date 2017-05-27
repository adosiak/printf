# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adosiak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/01 12:08:58 by adosiak           #+#    #+#              #
#    Updated: 2017/05/26 18:31:50 by adosiak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -c -g
INCLUDES = includes
SRCS = ft_strlen.c ft_strnew.c ft_strncat.c ft_strrev.c ft_strcpy.c\
	   ft_strcmp.c ft_strsub.c ft_strdup.c ft_atoi.c ft_strclr.c\
	   ft_putchar.c ft_putstr.c  ft_itoa.c ft_itoa_base.c ft_getsize.c\
	   ft_memset.c ft_memalloc.c\
	   main.c parse.c work_var.c
OBJS =  $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -I $(INCLUDES)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
