/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:54:05 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/22 19:21:02 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		ft_puzzle(t_tetr* tet, int num, size_t* field)
{
	// int		i = 0;
	// int		j = 1;
	int		res = 1;

	printf("num = %d \n", num);
	printf("складываем %llu и %llu\n", ft_l(tet,1)->t, ft_l(tet, 0)->t);
	res = ft_find_Y(ft_l(tet, 0), ft_l(tet,1), ft_l(tet,1)->x, ft_l(tet,1)->y, field);
	printf("result = %d \n", res);
	printf("%s=============================================%s\n", YELLOW, RESET);
	printf("складываем %llu и %llu\n", ft_l(tet,2)->t,ft_l(tet, 0)->t);
	res = ft_find_Y(ft_l(tet, 0), ft_l(tet,2), ft_l(tet,2)->x, ft_l(tet,2)->y, field);
	res = ft_find_Y(ft_l(tet, 0), ft_l(tet,2), ft_l(tet,2)->x, ft_l(tet,2)->y + 2, field);
	printf("result = %d \n", res);	
	printf("%s увеличиваем х ?%s\n", RED, RESET);
	res = ft_find_Y(ft_l(tet, 1), ft_l(tet,2), 0, 0, field);

	printf("%s=============================================%s\n", YELLOW, RESET);
	printf("fillit.c: складываем %llu и %llu\n", ft_l(tet,2)->t, ft_l(tet, 1)->t);         
	printf("fillit.c: result = %d \n", res);
return (0);
}
