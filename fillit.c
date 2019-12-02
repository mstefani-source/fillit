/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:54:06 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/02 13:22:26 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_refresh_list(t_tetr* tet)
{
	t_tetr* buf;

	buf = tet;
	while(buf)
	{
		buf->x = 0;
		buf->y = 0;
		buf = buf->next;
	}
	return (1);
}

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
	if (field < 4)
		field = 4;
	result = ft_greate_first_list(tet[0], 'A');
	test = result;
	while (++i < num_tet)
		test = ft_add_list(test, tet[i], ('A' + i));

	//ft_sort_list(result, ft_descent);
	ft_print_res(result);
    printf("%s=============================================%s\n", YELLOW, RESET);
	while (!ft_puzzle(result, &field))
		{
			ft_print_res(result);
			printf("%s puzzle not set, INCREASE FIELD %s \n", RED, RESET);
			ft_refresh_list(result);
			field++;
		}
	ft_print_res(result);
	printf("%s=============================================%s\n", YELLOW, RESET);
	print_res(result, field);
	return (0);
}
