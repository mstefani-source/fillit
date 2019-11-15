/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:10:44 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/15 23:28:22 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_coord(t_tetr* tetr1, t_tetr* tetr2, size_t field)
{
	if (!(tetr1->tetr<<(tetr2->x)<<(tetr2->y * 4) & tetr2->tetr))
		return (1);	 
	if ((tetr2->x + 4) >= field) //|| tetr2->tetr>>tetr2->x & 4369)
	{			
 		if ((tetr2->tetr>>tetr2->x) & 4369)
	 	{
	 		printf("impossible to move right!\n");
	 		return(0);
	 	}
	}
	tetr2->x++;
	printf("move right\n");
	if (ft_find_coord(tetr1, tetr2, field) == 1)
		return (1);
	return (0);
}
