/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:16:58 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/15 14:06:47 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr		*ft_sort_list(t_tetr *list, int (*cmp)(int, int)) 
{
	int		buf;
	char 	bufchar;
	t_tetr*	guf;
	int		flag = 1;

	guf = list;
	while (flag)
	{
		flag = 0;
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
					flag = 1;
				}
			}
			list = list->next;
		}
		list = guf;
	}
return (list);	
}
