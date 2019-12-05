/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:07:52 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/05 21:14:43 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_X(t_tetr* t, size_t* field)
 {
	t_tetr*	list = NULL;
	size_t 	offset_X;
	size_t	offset_XY;
	int		res = 1;
	static size_t	x;

	if (t->prev)
		list = t->prev;
	while (list && res != 0)
	{
		res = 0;
		if ((ft_abs(t->y - list->y) > 3) || (ft_abs(t->y - list->y) > 3))
				res = res | 1;
		offset_X = t->x >= list->x ? ft_mleft(list->t,(t->x - list->x)) : list->t >> (list->x - t->x);
		offset_XY = t->y >= list->y ? ft_mup(offset_X, t->y - list->y) : offset_X >> ((list->y - t->y) * 4);

		if (((offset_XY & t->t) == 0))
			res = res | 1;
	list = list->prev;
	}

	if (res == 1)
	{	
		x =  t->x;
		return (1);
	}
	if (!ft_can_we_moveX(t , 0 ,field))
	{
		t->x = 0;
		return (0);
	}
	if (ft_find_X(&(t_tetr){t->next, t->prev, t->t, t->x + 1, t->y, t->letter}, field))
		{
		t->x = x;
		return(1);
		}
	return(0);
 }
