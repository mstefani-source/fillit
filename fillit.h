/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:56:59 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/12 23:12:55 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 546
# include "libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_tetr
{
	struct s_tetr	*next;
	struct s_tetr	*prev;
	int				tetr;
	size_t			x;
	size_t			y;
	char			letter;
}					t_tetr;
int					*ft_makeup (int fd);
int					ft_calc (int fd);
int					ft_descent(int a, int b);
int					ft_calc_field (int num_tet);
void				ft_print_res (t_tetr* result);
int					ft_cmp_list (t_tetr* list1, t_tetr* list2);
t_tetr*				ft_greate_first_list (int tetr, char letter);
t_tetr*				ft_add_list (t_tetr* result, int tet, char letter);
t_tetr*				ft_l (t_tetr* list, int num);
t_tetr*				ft_sort_list(t_tetr *list, int (*cmp)(int, int), int num_tet);
void				ft_swap_list(t_tetr* first, t_tetr* second);
#endif
