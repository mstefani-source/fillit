/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:07:52 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/07 17:59:24 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_x(t_tetr* t, size_t* field)
 {
	t_tetr*	list = NULL;
	size_t 	offset_x;
	size_t	offset_xy;
	int		res = 1;

	if (t->prev)
		list = t->prev;
	while (list && res != 0)
	{
		res = 0;
		if ((ft_abs(t->y - list->y) > 3) || (ft_abs(t->y - list->y) > 3))
			res = res | 1;
		offset_x = t->x >= list->x ? ft_mleft(list->t,(t->x - list->x)) : ft_mright(list->t, (list->x - t->x));
		offset_xy = t->y >= list->y ? ft_mup(offset_x, t->y - list->y) : offset_x >> ((list->y - t->y) * 4);
		if (((offset_xy & t->t) == 0))
			res = res | 1;
	list = list->prev;
	}
	if (res == 1)
		return (1);
	if (!ft_can_we_movex(t ,field))
	{
		t->x = 0;
		return (0);
	}
	t->x++;
	if (ft_find_x(t, field))
		return(1);
	t->x = 0;
	return(0);
 }
