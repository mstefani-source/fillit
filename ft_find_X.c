/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:07:52 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/29 18:53:34 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_X(t_tetr* list, t_tetr* t, size_t* field)
 {
	size_t 	x = 0;
	size_t 	y = 0;
	size_t 	offset_X;
	size_t	offset_Y;
	int		res = 1;
	
	while (list->letter != t->letter)
	{
	
		res = 0;
		x = 0;
		y = 0;
		offset_X = ft_abs(list->x - t->x);
		offset_Y = ft_abs(list->y - t->y);
		printf("trying %c and %c \n", t->letter, list->letter);
			if ((offset_X > 3) || (offset_Y > 3))
			{
				printf("s%too far from each other, go NEXT %s\n", RED, RESET);
				return (1);
			}
			while ((ft_mup(ft_mup(ft_mleft(list->t >> offset_X, x), offset_Y), y) & t->t) != 0 && ft_can_we_moveX(t, x, field))
				x++;
			if ((ft_mup(ft_mup(ft_mleft(list->t >> offset_X, x), offset_Y), y) & t->t) == 0)
				res = res | 1;
			
	list = list->next;
	}
	if (res == 0)
		{
			printf("%swe didn't found place for %llu%s\n", RED, t->t, RESET);
			t->x = 0;
		}
	else 
		{
			printf("%s found place for %llu %s\n",GREEN, t->t ,RESET);
			t->x = t->x + x;
			t->y = t->y + y;
		}
	return (res);
}
