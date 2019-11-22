/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_Y.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:46:30 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/22 19:12:01 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_Y(t_tetr* t1, t_tetr* t2, size_t x, size_t y, size_t* field)
{

	if ((ft_mup(ft_mleft(t1->t, x), y) & t2->t) == 0)
	{
		printf("ft_find_Y: FOUND PLACE FOR %llu!!!\n", t2->t);
		t2->x = x;
		t2->y = y;
		return (1);
	}	 
	if ((((x + 4) >= *field) && ((t2->t>>x & 4369) !=0)) && (((y + 4) >= *field) && (((t2->t>>(y*4)) & 15)!=0)))
	{
		printf("ft_find_Y: for %llu места не нашлось", t2->t);
		printf(" в данный момент x = %zu y = %zu\n", x, y);
		t2->x = 0;
		t2->y = 0;
		return (0);
	}

	if (!ft_can_we_moveY(t2, y, field))
	// {
	// 	printf("ft_find_Y: We reach Ymax and can't move down, moving tetr right!\n");
	// 	ft_find_X(t1, t2, x, y, field);
	// }
	
	return (ft_find_X(t1, t2, x, y, field));
	return (0);
}
