/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:16:58 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/12 23:24:01 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr		*ft_sort_list(t_tetr *list, int (*cmp)(int, int), int num_tet) 
{
	int		buf;
	char 	bufchar;
	int		flag = 1;

	while (flag < (num_tet*num_tet))
	{
		flag++;
		while (list)
		{
			if (list->next)
				{
					if (cmp(list->tetr, (list->next)->tetr))
					 {
					 	buf = (list->next)->tetr;
					 	bufchar = (list->next)->letter;
					 	(list->next)->tetr = list->tetr;
					 	(list->next)->letter = list->letter;
					 	list->tetr = buf;
					 	list->letter = bufchar;
					 }
				}
			list = list->next;
		}
	}
return(list);	
}
