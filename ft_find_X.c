/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:07:52 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/07 17:59:24 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_X(t_tetr* t, size_t* field)
 {
	t_tetr*	list = NULL;
	size_t 	offset_X;
	size_t	offset_XY;
	int		res = 1;

	if (t->prev)
		list = t->prev;
	while (list && res != 0)
	{
		res = 0;
		if ((ft_abs(t->y - list->y) > 3) || (ft_abs(t->y - list->y) > 3))
				res = res | 1;
		offset_X = t->x >= list->x ? ft_mleft(list->t,(t->x - list->x)) : ft_mright(list->t, (list->x - t->x));
		offset_XY = t->y >= list->y ? ft_mup(offset_X, t->y - list->y) : offset_X >> ((list->y - t->y) * 4);
		if (((offset_XY & t->t) == 0))	
			res = res | 1;
	list = list->prev;
	}
	if (res == 1)						// всё отлично, мы нашли координату Х для t->t и ниодна другая тетраминка на поле её не пересекает
		return (1);						// возвращаем 1
	if (!ft_can_we_moveX(t , 0 ,field)) // если не нашли координату Х то проверяем можем ли мы двинуть t по Х на один шаг
	{
		t->x = 0;						// всё плохо, мы не можем двинуть то обнуляем координату Х 
		return (0);						// и возвращаем 0 в функцию findXY чтоб там попытаться увеличить Y
	}
	// тут мы оказываемся в том случае когда мы не нашли координату Х но можем двигать тетраминку влево поэтому мы увеличиваем координату t->x
	t->x++;
	if (ft_find_X(t, field))			// это собственно рекурсия с увеличенной координато Х на один.
		return(1);
	t->x = 0; 					// на всякий случай обнулим еще разок.
	return(0);
 }
