/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_match.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:10:44 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/19 18:45:33 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_not_match(t_tetr* t1, t_tetr* t2, size_t x, size_t y, size_t field)
{
	//int res;
	printf("==================================\n");	
	
	// printf("compare %llu %llu = %llu\n",(t1->t)<<x<<(y * 4), t2->t, t1->t<<x<<(y * 4) & t2->t);
	// printf("(x + 4) >= field  = %d\n",((x + 4) >= field));
	// printf("offset %zu tetr->tetr>>x = %llu\n", x, t1->t<<x);
	// printf("tetr->tetr>>x & 4369 = %llu\n",(t2->t>>x) & 4369);
	
	if ((t1->t<<x<<(y * 4) & t2->t) == 0)
	{
	    printf("FOUND PLACE FOR %llu!!!", t2->t);
		printf("  it's x = %zu y = %zu\n", x, y);
		t2->x = x;
		t2->y = y;
		return (1);	 
	}
	// printf("X = %zu\n", x);
	// printf("Y = %zu\n", y);
	
	// printf ("край по Х %d\n", (((x + 4) >= field)&&((t2->t>>x) & 4369)));
	// printf ("край по Y %d\n", ((y + 4) >= field)&&((t2->t>>(y*4)) & 15));
	// printf ("X&Y %d\n",((((x + 4) >= field)&&((t2->t>>x) & 4369)!=0) & (((y + 4) >= field)&&((t2->t>>(y*4)) & 15)!=0)) == 1);

	if (((x + 4) >= field)&&((t2->t>>x) & 4369)!=0) 
	{			
		printf("NO PLACE on this column we should increase Y! \n");
		return(0);
	}

	printf("%zu %zu WE can move !!\n", x, y);
	sleep (1);
	
	if (ft_not_match(t1, t2, x + 1, y, field))
		return (1);
	else 
	{
		x = 0;
		printf("X = %zu\n", x);
		printf("Y = %zu\n", y);
		if (((y + 4) >= field)&&((t2->t>>(y*4)) & 15)!=0)
		{
			printf("NO PLACE on this square and impossible to move down!\n");
			return(0);
		}
		if (ft_not_match(t1, t2, x, y + 1, field))
		return (1);
	}
    return (0);
}
