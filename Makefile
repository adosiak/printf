# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adosiak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/01 12:08:58 by adosiak           #+#    #+#              #
#    Updated: 2017/03/14 16:18:36 by adosiak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -c -g
INCLUDES = includes
SRCS = ft_strmap.c ft_strlen.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	   ft_strcmp.c ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_strsub.c \
	   ft_strjoin.c ft_strstr.c ft_strnstr.c ft_strcat.c ft_strncat.c \
	   ft_strlcat.c ft_strdup.c ft_strchr.c ft_strrchr.c ft_toupper.c \
	   ft_tolower.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	   ft_isprint.c ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_memchr.c\
	   ft_memset.c ft_bzero.c ft_memmove.c ft_memalloc.c ft_memdel.c \
	   ft_strclr.c ft_strnew.c ft_strdel.c ft_striter.c ft_striteri.c\
	   ft_atoi.c ft_strtrim.c ft_putchar.c ft_putstr.c ft_putendl.c \
	   ft_strsplit.c ft_itoa.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		 ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
		 ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strrev.c \
		 ft_itoa_base.c ft_power.c ft_getsize.c ft_max.c ft_get_next_line.c \
		 parse.c work_var.c printf.c type_sc.c type_d.c type_u.c length.c \
		 unsign_itoa_base.c type_p.c printfree.c

OBJS =  $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS)  -I $(INCLUDES)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
