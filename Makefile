# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 17:09:34 by mstefani          #+#    #+#              #
#    Updated: 2019/12/07 17:59:46 by mstefani         ###   ########.fr        #
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
	    ft_l.c \
		ft_sort_list.c \
		ft_descent.c \
		ft_list_test.c \
		ft_not_match.c \
		ft_find_X.c \
		ft_mleft.c \
		ft_mright.c \
		ft_mup.c \
		ft_puzzle.c \
		print_res.c \
		ft_can_we_moveX.c \
		ft_can_we_moveY.c

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
