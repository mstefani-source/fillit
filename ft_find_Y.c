/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_Y.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:46:30 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/21 20:05:14 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_Y(t_tetr* t1, t_tetr* t2, size_t x, size_t y, size_t* field)
{
	if ((ft_mup(ft_mleft(ft_mup(ft_mleft(t1->t, x), y),t1->x),t1->y) & t2->t) == 0 )
	{
//		printf("ft_find_Y: FOUND PLACE FOR %llu!!!\n", t2->t);
		t2->x = x;
		t2->y = y;
		return (1);
	}	 
	if ((((x + 4) >= *field) && ((t2->t>>x & 4369) !=0)) && (((y + 4) >= *field) && (((t2->t>>(y*4)) & 15)!=0)))
	{
		// printf("ft_find_Y: места не нашлось");
		// printf(" в данный момент x = %zu y = %zu\n", x, y);
		t2->x = 0;
		t2->y = 0;
		return (0);
	}

	if (((y + 4) >= *field) && ((t2->t>>(y * 4)) & 15) != 0)
	{
		// printf("ft_find_Y: We reach Ymax and can't move down, moving tetr right!\n");
		ft_find_X(t1, t2, x, y, field);
	}
	
	if (ft_find_X(t1, t2, x, y, field) == 1)
		{
		//printf("ft_find_Y: place fouded! x = %zu y = %zu\n",x, y);
		return(1);
		}
	return (0);
}
