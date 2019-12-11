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

long long unsigned int	ft_offset_xy(t_tetr *list, t_tetr *t)
{
	long long unsigned int	offset_xy;

	offset_xy = list->x >= t->x ? ft_mleft(t->t, (list->x - t->x)) \
	: ft_mright(t->t, (t->x - list->x));
	offset_xy = list->y >= t->y ? ft_mup(offset_xy, list->y - t->y) \
	: offset_xy >> ((t->y - list->y) * 4);
	return (offset_xy);
}

int ft_far(t_tetr *list, t_tetr *t)
{
	if ((ft_abs(list->y - t->y) > 3) || (ft_abs(list->y - t->y) > 3))
		return (1);
	return (0);
}

int		ft_find_x(t_tetr *list, size_t *field)
{
	t_tetr*		t;
	int			res;

	t = list->prev;
	res = 1;
	while (t && res != 0)
	{
		res = 0;
		if (ft_far(list, t) || ((ft_offset_xy(list, t) & list->t) == 0))
			res = res | 1;
		t = t->prev;
	}
	if (res == 1)
		return (1);
	if (!ft_can_we_movex(list, field))
	{
		list->x = 0;
		return (0);
	}
	list->x++;
	if (ft_find_x(list, field))
		return (1);
	return (0);
}
