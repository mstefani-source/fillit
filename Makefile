# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 17:09:34 by mstefani          #+#    #+#              #
#    Updated: 2019/11/09 22:22:20 by mstefani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADERS	=-I fillit.h

SRC = fillit.c \
		ft_makeup.c \
		ft_calc.c \
		ft_calc_field.c \
		ft_greate_first_list.c \
		ft_print_res.c \
		ft_add_list.c \
	    ft_l.c

LIBOBJ=$(SRC:.c=.o)

LIBNAME = ./libft/libft.a

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(LIBOBJ)
		make -C ./libft
		gcc $(CFLAGS) $(LIBOBJ) $(LIBNAME) -o $(NAME) $(HEADERS)

%.o:%.c
	gcc $(CFLAGS) $< -c -o $@

all: $(NAME)
   
clean:
	make -C ./libft clean
	rm -rf $(LIBOBJ)

fclean: clean
	make -C ./libft fclean
	-rm -f $(NAME)

re: fclean all
