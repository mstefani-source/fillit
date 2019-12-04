/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:54:05 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/04 17:43:38 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_XY(t_tetr* t, size_t* field)
{
	int		find_X;

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
		return(1);

	if (ft_can_we_moveY(t, 0, field))
	{
		printf("we can increase Y for %llu, - '%c' x = %zu y = %zu\n", t->t, t->letter, t->x, t->y);
		ft_find_XY(&(t_tetr){t->next, t->prev, t->t, t->x, t->y + 1, t->letter}, field);
	}
	if (find_X)
	{
		printf("%sft_find_XY: возвращает 1%s\n", GREEN, RESET);
		return(1);
	}
	else
	{
		printf("%sft_find_XY: возвращает 0%s\n", RED, RESET);
		t->y = 0;
		return(0);
	}
 }

int		ft_puzzle(t_tetr* list, size_t* field)
{
	int		find_XY;
	int		res = 0; // 0 сложилось 1 - не сложилось
	t_tetr*	buf;

	buf = list;
    
	while (buf->prev && res == 0)
	{
		res = 0;
		printf("ft_puzzle: trying to find place for %c\n", list->letter);
		find_XY = ft_find_XY(list, field);
		if (!find_XY)
		{
			res = res | 1;
			printf("%sft_find_XY: возвращает 0%s\n", RED, RESET);
		}
		buf = buf->prev;
	}
	if (res)  // если не сложилось надо попробывать подвинуть предыдущую и запустить опять пазл
	{
		printf("we should step back to '%c' and increase it's X coord if we can\n", buf->letter);
		printf("now we reach '%c' whith x = %zu, y = %zu\n", list->letter, list->x, list->y);
		buf->x++;
		sleep(1);
		ft_puzzle(list, field);
	}
	if (list->next == NULL)
	{
		printf("ft_puzzle: we reach %c \n", list->letter);
		return (1);
	}
	if (ft_puzzle(list->next, field))
		return (1);
	return(0);
}
