/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_XY.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:46:39 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/29 19:01:15 by mstefani         ###   ########.fr       */
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

if (ft_find_X(list, t, field))
	return (1);
if (ft_can_we_moveY(list, t->y, field))
	ft_find_XY(list, &(t_tetr){t->next, t->prev, t->t, t->x, t->y + 1, t->letter}, field);
return (0);
}
