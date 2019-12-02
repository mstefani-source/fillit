/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:54:05 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/02 22:51:22 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		ft_find_XY(t_tetr* list, t_tetr* t, size_t* field)
{

if (t->prev == NULL)
	{
		printf("%s we dont need to search XY for %llu  it's first element%s\n", GREEN, t->t, RESET);
		return (1);
	}

if (!ft_find_X(list, t, field) && !ft_can_we_moveY(t, t->y, field))
	return (0);

if (!ft_can_we_moveY(t, t->y, field))
	return (0);
printf("call find XY list = %c, t = %c\n", list->letter, t->letter);
ft_find_XY(list, &(t_tetr){t->next, t->prev, t->t, t->x, t->y + 1, t->letter}, field);
return(1);
}


int		ft_puzzle(t_tetr* list, size_t* field)
{
	t_tetr*	buf;
	int		find_XY;

	buf = list;
	
	find_XY = ft_find_XY(list, buf, field);
	if (list->next == NULL)
		{
			printf("ft_puzzle: we reach %c find_XY = %d\n", list->letter, find_XY);
			return (1);
		}
  //  sleep(1);
	ft_puzzle(buf->next, field);
	return (1);
}
