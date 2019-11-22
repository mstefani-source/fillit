/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:07:52 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/22 19:14:58 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_X(t_tetr* t1, t_tetr* t2, size_t x, size_t y, size_t* field)
{
	if((t1->x + x) >= *field)
	{
		printf("*field = %zu\n", *field);
		printf("t1->x = %zu ", t1->x);
		printf("x = %zu\n", x);
		printf("хуй\n");
	}
	if ((ft_mup(ft_mleft(t1->t, x) ,y) & (t2->t)) == 0)	
	{
		printf("ft_findX: FOUND PLACE FOR %llu!!!", t2->t);
		printf(" it's x = %zu y = %zu\n", x, y);
		if(((t1->x + x + 4) >= *field) && ((t2->t>>(t1->x + x) & 4369) != 0))
		{
			printf("*field = %zu\n", *field);
			printf("t1->x = %zu ", t1->x);
			printf("x = %zu\n", x);
			printf("ft_find-X: тетраминка не влазит в ворота! возвращаем 0 \n");
			return(0);
		}
		else
		{
			t2->x = x;
			t2->y = y;
			return (1);	
		}	
	}
	if ((((x + 4) >= *field) && ((t2->t>>x & 4369) !=0)) && (((y + 4) >= *field) && (((t2->t>>(y*4)) & 15)!=0)))
		{
			printf("ft_find_X: места для %llu не нашлось!\n", t2->t);
			t2->x = 0;
			t2->y = 0;
			return (0);
		}	
	if (!ft_can_we_moveX(t2, x, field)) 
	{
		printf("We reach Xmax on this column and cant move right anymore, we should increase Y! \n");
		return (0);
	}
	return (ft_find_X(t1, t2, x + 1, y, field));
}
