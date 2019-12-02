/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:07:52 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/02 21:13:44 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_X(t_tetr* list, t_tetr* t, size_t* field)
 {
	size_t 	x = 0;
	size_t 	y = 0;
	size_t 	offset_X;
	size_t	offset_XY;
	int		res = 1;

	while (list->letter != t->letter)
	{
		res = 0;
		x = 0;
		y = 0;
		if ((ft_abs(t->y - list->y) > 3) || (ft_abs(t->y - list->y) > 3))
			{
				printf("s%too far from each other, go NEXT %s\n", RED, RESET);
				return (1);
			}
		offset_X = t->x >= list->x ? list->t << (t->x - list->x) : list->t >> (list->x - t->x);
		offset_XY = t->y >= list->y ? ft_mup(offset_X, t->y - list->y) : offset_X >> ((list->y - t->y) * 4);
		
		
		while ((ft_mup(ft_mleft(offset_XY, x), y) & t->t) != 0 && ft_can_we_moveX(t, x, field))
		{
			x++;
			printf("trying %c and %c with x = %zu , y = %zu\n", t->letter, list->letter, t->x + x, t->y + y);
		}
		if ((ft_mup(ft_mleft(offset_XY, x), y) & t->t) == 0)
		 {
			res = res | 1;
			printf("%sfound for %llu x = %zu y = %zu %s \n",GREEN, t->t, t->x+x, t->y+y, RESET);
		 }

	list = list->next;
	}

	if (res == 0)
	{
		printf("%swe didn't found place for %llu with x = %zu and y = %zu %s\n", RED, t->t, t->x + x, t->y + y, RESET);
		t->x = 0;
		return (0);
	}
	t->x = t->x + x;
	t->y = t->y + y;
	return (1);
 }
