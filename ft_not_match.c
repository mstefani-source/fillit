/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_match.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:10:44 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/17 20:39:34 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_not_match(t_tetr* t1, t_tetr* t2, size_t x, size_t y, size_t field)
{
	int res;
	printf("==================================\n");	
	printf("x = %zu y = %zu\n", x,y);
	printf("compare %llu %llu = %llu\n",(t1->t)<<x<<(y * 4), t2->t, t1->t<<x<<(y * 4) & t2->t);
	printf("(x + 4) >= field  = %d\n",((x + 4) >= field));
	printf("offset %zu tetr->tetr>>x = %llu\n", x, t2->t>>x);
	printf("tetr->tetr>>x & 4369 = %llu\n",(t2->t>>x) & 4369);
	
	if ((t1->t<<x<<(y * 4) & t2->t) == 0)
	{
	    printf("FOUND PLACE FOR %llu!!!", t2->t);
		printf("  it's x = %zu y = %zu\n", x, y);
		t1->x = x;
		t2->y = y;
		return (1);	 
	}

	 if (((x + 4) >= field)&&((t2->t>>x) & 4369)!=0)  
	 {			
	  		printf("NO PLACE on this row and impossible to move right!\n");
	  		return(0);
	 }
	printf("%zu %zu WE can move !!\n", x, y);
	sleep (1);
	res = ft_not_match(t1, t2, x + 1, y, field);
	if (res)
		return (1);
	else 
		if (!res)
		{
			x = 0;
			res = ft_not_match(t1, t2, x, y + 1, field);
			if (res)
				return (1);
			return (0);
		}
	printf("res = %d\n",res);
    return (0);
}
