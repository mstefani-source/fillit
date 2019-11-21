/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:54:05 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/21 20:58:49 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		ft_puzzle(t_tetr* tet, int num, size_t* field)
{
	// int		i = 0;
	// int		j = 1;
	int		res = 1;

	// while (i < num)
	// {
	// 	printf("tetr i = %lli \n", ft_l(tet,i)->t);
	// 	while (j < num)
	// 	{
	// 		if (ft_find_Y(ft_l(tet, i), ft_l(tet,j), ft_l(tet,j)->x, ft_l(tet,j)->y, field) == 0)
	// 		{
	// 			printf("place for %llu not found\n", ft_l(tet,j)->t);
	// 			res = 0;
	// 		}
	// 		else 
	// 			printf("place for %llu found x = %zu y = %zu \n", ft_l(tet,j)->t, ft_l(tet,j)->x, ft_l(tet,j)->y);
	// 	j++;
	// 	}
	// i++;
	// j = 0;
	// }
	printf("num = %d \n", num);
	res = ft_find_Y(ft_l(tet, 1), ft_l(tet,2), ft_l(tet,2)->x, ft_l(tet,2)->y, field);
	printf("res = %d \n", res);
return (0);
}
