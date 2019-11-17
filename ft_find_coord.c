/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:10:44 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/17 20:39:34 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_coord(t_tetr* tetr, size_t x, size_t y, size_t field)
{
	printf("==================================\n");	
	printf("x = %zu y = %zu\n", x,y);
	printf("compare %llu %llu = %llu\n",((tetr->prev)->tetr)<<x<<(y * 4),tetr->tetr, (tetr->prev)->tetr<<x<<(y * 4) & tetr->tetr);
	printf("(x + 4) >= field  = %d\n",((x + 4) >= field));
	printf("tetr->tetr>>x = %llu\n", tetr->tetr>>x);
	printf("tetr->tetr>>x & 4369 = %llu\n",(tetr->tetr>>x) & 4369);
	
	if (((tetr->prev)->tetr<<x<<(y * 4) & tetr->tetr) == 0 || ((((x + 4) >= field) && ((tetr->tetr>>x) & 4369) != 0) && (((y + 4) >= field)&&((tetr->tetr>>y) & 15)!=0)))// && !(((x + 4) >= field)&&((tetr->tetr>>x) & 4369)!=0))//&& (((y + 4) >= field)&&((tetr->tetr>>y) & 15)!=0)!=0)
	{
	    printf("FOUND PLACE FOR %llu!!!", tetr->tetr);
		printf("  it's x = %zu y = %zu\n", x, y);
		// tetr->x = x;
		// tetr->y = y;	
		tetr->x = x;
		tetr->y = y;
		return (1);	 
	}
	// if ((((x + 4) >= field)&&((tetr->tetr>>x) & 4369)!=0))// && (((y + 4) >= field)&&((tetr->tetr>>y) & 15)!=0))  
	// {			
	//  		printf("NO PLACE on this row and impossible to move right!\n");
	//  		return(0);
	// }
	// if (((y + 4) >= field)&&((tetr->tetr>>y) & 15)!=0)
	// {			
	//  		printf("NO PLACE on this column and impossible to move down!\n");
	//  		return(0);
	// }
	// sleep(1);

	printf("%zu %zu WE can move !!\n", x, y);
	ft_find_coord(tetr, x + 1, y, field);
	ft_find_coord(tetr, x, y + 1, field);

	printf("finally x = %zu y = %zu \n", x, y);
	// return (1);
	// else 
	// 	{
	// 	x = 0;
	// 	printf("%zu %zu after move down\n", x, y);
	// 	if (ft_find_coord(tetr, x, y + 1, field) == 1)
	// 	return (1);
	// 	}
	return (0);
}
