/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:54:06 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/15 23:28:21 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		i=0;
	size_t	field;
	int		fd;
	int		*tet;
	int		num_tet;
	t_tetr	*result;
	t_tetr	*test;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "can't open file ", 16);
		ft_putendl(argv[1]);
		return (0);
	}
	else
	{
		tet = ft_makeup(fd);
		if (!tet)
			return (0);
		fd = open(argv[1], O_RDONLY);
		num_tet = ft_calc(fd);
	}
	field = ft_calc_field(num_tet);
	printf("field =%zu\n", field);
	result = ft_greate_first_list(tet[0], 'A');
	test = result;
	while (++i < num_tet)
		test = ft_add_list(test, tet[i], ('A' + i));
	ft_sort_list(result, ft_descent);
	ft_print_res(result);
	i = 0;
while(i < num_tet - 1)
{
	while (ft_find_coord(ft_l(result, i), ft_l(result, i+1), field) == 0)
	{
		ft_l(result, i+1)->y++;
		ft_l(result, i+1)->x = 0;
		 if (ft_l(result, i+1)->y + 4 > field && (ft_l(result, i+1)->tetr >> (ft_l(result, i+1)->y * 4) & 15) != 0)
		 {
		 	printf("popavsya y \n");
		 }
	}
	i++;
}
	// while (ft_find_coord(ft_l(result, 1), ft_l(result, 2), field) == 0)
	// {
	// 	ft_l(result, 2)->y++;
	// 	ft_l(result, 2)->x = 0;
	// 	 if (ft_l(result, 2)->y + 4 > field && (ft_l(result, 2)->tetr >> (ft_l(result, 2)->y * 4) & 15) != 0)
	// 	 {
	// 	 	printf("popavsya y \n");
	// 	 }
	// }

	ft_print_res(result);
	return (0);
}
