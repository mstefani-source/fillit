/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:07:52 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/21 20:08:10 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_X(t_tetr* t1, t_tetr* t2, size_t x, size_t y, size_t* field)
{
	// printf("field = %zu\n", field);
	// printf("wait a minet  it's x = %zu y = %zu\n", x, y);
	// printf("and t1->x = %zu t1->y = %zu\n", t1->x, t1->y);
	// printf("and t2->x = %zu t2->y = %zu\n", t2->x, t2->y);
	// printf("ft_mup(ft_mup(ft_mleft(ft_mleft(t1->t, x) ,y * 4), t1->x), t1->y * 4) = %d\n", ft_mup(ft_mup(ft_mleft(ft_mleft(t1->t, x) ,y * 4), t1->x), t1->y * 4));
	// printf("t2->t = %llu\n",t2->t);
	// printf(" ПЕРЕЧЕЧЕНИЕ = %llu\n", ft_mup(ft_mup(ft_mleft(ft_mleft(t1->t, x) ,y * 4), t1->x), t1->y * 4) & t2->t);
	
	if ((ft_mup(ft_mleft(ft_mup(ft_mleft(t1->t, x) ,y), t1->x), t1->y) & t2->t) == 0)	
	{
		// printf("ft_findX: FOUND PLACE FOR %llu!!!", t2->t);
		// printf("  it's x = %zu y = %zu\n", x, y);
		t2->x = x;
		t2->y = y;
		return (1);
	}
	if ((((x + 4) >= *field) && ((t2->t>>x & 4369) !=0)) && (((y + 4) >= *field) && (((t2->t>>(y*4)) & 15)!=0)))
		{
			// printf("ft_find_X: места не нашлось!\n");
			t2->x = 0;
			t2->y = 0;
			return (0);
		}	
	//sleep (1);
	if (((x + 4) >= *field)&&((t2->t>>x) & 4369)!=0) 
	{
		// printf("We reach Xmax on this column and cant move right anymore, we should increase Y! \n");
		x = 0;
		if (ft_find_Y(t1, t2, x, y + 1, field))
			return (1);
		return (0);
	}
	// printf("we have x = %zu y = %zu and able increaze X \n", x, y);
	if (ft_find_X(t1, t2, x + 1, y, field))
		return (1);
	return (0);
}
