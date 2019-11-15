/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_crd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:44:59 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/15 18:03:31 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

int		ft_find_crd(int tetr1, int tetr2, int x1, int y1, int x2, int y2, size_t field)
{
	if (!(tetr1<<x2<<(y2*4) & tetr2))
		return (1);	 
	if ((x2 + 4) >= field)
	{			
 		if ((tetr2>>x2) & 4369)
	 	{
	 		printf("impossible to move right!\n");
			x1 = 0;
			y2++; 
	 	}
	}
	x2++;
	if (ft_find_crd(tetr1, tetr2, x1, y1, x2, y2, field) == 1)
		{
		printf("place fouded! x = %zu y = %zu\n",x2, y2);
		return(1);
		}
	return (0);
}
