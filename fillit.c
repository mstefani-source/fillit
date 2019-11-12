/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:54:06 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/12 23:09:54 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	int     i = 0;
	int		field;
    int		fd;
    int*	tet = NULL;
    int		num_tet = 0;
    int		Xmax,Ymax;
	t_tetr*	result;
	t_tetr* test;
    
    if (argc != 2)
    {
		ft_putstr("usage: fillit source_file\n");
		return (0);
    }
    fd = open(argv[1], O_RDONLY);
    if(fd < 0)
    {
    	write(1, "can't open file ", 16);
    	ft_putendl(argv[1]);
    }
    else
    {
    	tet = ft_makeup(fd);
		if (!tet)
			return(0); 
    	fd = open(argv[1], O_RDONLY);
    	num_tet = ft_calc(fd);
    }
	field = ft_calc_field(num_tet);

	Xmax = Ymax = field;
	result = ft_greate_first_list(tet[0], 'A');
	test = result;
	while (++i < num_tet)
			test = ft_add_list(test, tet[i], ('A'+ i));
	ft_print_res(result);
	printf("=====\n");
	ft_sort_list(result, ft_descent);	
//	printf("1\n");
//	test = ft_l(result, 3);
//	ft_print_res(result);
//	test = ft_sort_list(result, num_tet);
//	printf("=====\n");
	ft_print_res(result);
//	printf("test-letter = %c\n",test->letter);
	return(0);
}
