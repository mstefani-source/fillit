/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:54:05 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/05 23:14:26 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_XY(t_tetr* t, size_t* field)
{
	static int		find_X;
	static size_t 	y;
	static size_t	x;

	if (t->prev == NULL)
	{
		printf("%s we dont need to search XY for %llu  it's first element%s\n", GREEN, t->t, RESET);
		return (1);
	}

	find_X = ft_find_X(t, field);

	if (!find_X && !ft_can_we_moveY(t, 0, field))
	{
		printf("%swe can't found X and can't increase Y for '%c' -> %llu sorry%s\n",RED, t->letter, t->t,RESET);
		return (0);
	}
	if (find_X)
	{
		y = t->y;
		x = t->x;
		return(1);
	}
	if (ft_can_we_moveY(t, 0, field))
	{
		printf("we can increase Y for %llu, - '%c' x = %zu y = %zu\n", t->t, t->letter, t->x, t->y);
		ft_find_XY(&(t_tetr){t->next, t->prev, t->t, t->x, t->y + 1, t->letter}, field);
	}
	if (find_X)
	{
		printf("%sft_find_XY: return 1%s\n", GREEN, RESET);
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
		printf("ft_POD_puzzle: trying to find place for %c\n", list->letter);
		find_XY = ft_find_XY(list, field);
		if (find_XY)
		{
			res = res | 1;
			printf("%s FT_POD_PUZZLE: ft_find_XY returns 1%s\n", RED, RESET);
		}
		buf = buf->prev;
	}
	return (res);
}

int		ft_puzzle(t_tetr* list, size_t* field)
{
	if (list == NULL)
		return (1); 
	
	if (!ft_pod_puzzle(list, field))
		return (0);
	
	if(ft_puzzle(list->next, field))
		return (1);
	else
	{
		printf("here we should make a step back !\nlet's try cast ft_XY for \n %llu x= %zu, y = %zu\n", list->t, list->x + 1, list->y);
	
		if (!ft_can_we_moveX(list, 0, field))
			{
				if (!ft_can_we_moveY(list, 0, field))
					return(0);
				else
				{
					list->x = 0;
					list->y++;
					ft_puzzle(list->next, field);	
				}
			}
		list->x++;
		if (ft_puzzle(list->next, field))
			return (1);
		return (0);
	}
	return(0);
}
