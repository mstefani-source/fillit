/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:56:59 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/04 14:26:59 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 546
# define RESET   	"\033[0m"
# define RED     	"\033[1;31m"
# define YELLOW		"\033[1;33m"
# define GREEN		"\033[0;32m"
# define WHITE   	"\033[1;37m"
# include "libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct				s_tetr
{
	struct s_tetr			*next;
	struct s_tetr			*prev;
	long long unsigned int	t;
	size_t					x;
	size_t					y;
	char					letter;
}							t_tetr;

int					*ft_makeup (int fd);
int					ft_calc (int fd); /* calculate number of tetramoniks */
int					ft_descent (int a, int b);
size_t				ft_calc_field (int num_tet); /* calculate minimum field, return side of square */
void				ft_print_res (t_tetr *result);
t_tetr				*ft_greate_first_list (int tetr, char letter);
t_tetr				*ft_add_list (t_tetr *result, int tet, char letter);
t_tetr				*ft_l (t_tetr *list, int num);
int					ft_find_X(t_tetr* t, size_t* field);
int					ft_find_XY(t_tetr* t, size_t* field);
int					ft_mleft(int d, int offset);
int					ft_mup(int d, int offcet);
int					ft_puzzle(t_tetr* tet, size_t* field);
int					print_res(t_tetr* lst, int dlina);
int					ft_can_we_moveX(t_tetr* t, size_t x, size_t* field);
int					ft_can_we_moveY(t_tetr* t, size_t y, size_t* field);
int					ft_can_i_get_X(t_tetr* candidat, t_tetr* resident, size_t x, size_t* field);
#endif
