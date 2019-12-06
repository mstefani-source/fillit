/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:54:05 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/06 19:28:55 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_XY(t_tetr* t, size_t* field)
{
	static int		find_X;
	static size_t 	y = 0;
	static size_t	x = 0;

	if (t->prev == NULL)
		return (1);
	find_X = ft_find_X(t, field);
	if (!find_X && !ft_can_we_moveY(t, 0, field))
			return (0);
	if (find_X)
	{
		y = t->y;
		x = t->x;
		return(1);
	}
	if (ft_can_we_moveY(t, 0, field))
		ft_find_XY(&(t_tetr){t->next, t->prev, t->t, t->x, t->y + 1, t->letter}, field);
	if (find_X)
	{
		t->x = x;
		t->y = y;
		return(1);
	}
	else
	{
		t->y = 0;
		return(0);
	}
}
int	ft_pod_puzzle(t_tetr* list, size_t* field)
{
	t_tetr*		buf = NULL;
	int			find_XY;
	int			res = 1;

	buf = list;
	
	while (buf->prev && res != 0)
	{
		res = 0;
		find_XY = ft_find_XY(list, field);
		if (find_XY)
			res = res | 1;
		buf = buf->prev;
	}
	return (res);
}

int		ft_puzzle(t_tetr* list, size_t* field)
{
	if (list == NULL)
		return (1); 
	
	if (!ft_pod_puzzle(list, field))
	{
		printf("%s%llu is NOT SET!! x = %zu y = %zu %s\n",RED,list->t, list->x, list->y,RESET);
		return (0);
	}
//	printf("%s%llu is SET!! x = %zu y = %zu %s\n",GREEN, list->t, list->x, list->y, RESET);
	if(ft_puzzle(list->next, field))
		return (1);
	else
	{
		if (!ft_can_we_moveX(list, 0, field))
			{
//				printf("we cant set %llu with x = %zu and y = %zu\n", list->t, list->x + 1, list->y);
				if (!ft_can_we_moveY(list, 0, field))
					return(0);
				else
				{
					list->x = 0;
					list->y++;
//					printf("%s increasing y %llu x= %zu y = %zu %s\n", RED, list->t, list->x, list->y, RESET);
					ft_puzzle(list->next, field);	
				}
			}
		list->x++;
		if (ft_puzzle(list, field))
			return (1);
		return (0);
	}
	return(0);
}
