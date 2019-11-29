/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:54:05 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/29 18:58:17 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		ft_puzzle(t_tetr* list, size_t* field)
{
	t_tetr*	buf;

	buf = list;
	
	while (buf && ft_find_XY(list, buf, field))
	{
		printf("%s it was try to set %c%s\n", GREEN, buf->letter, RESET);
		printf("%s NOW %c, got x = %zu and y = %zu%s\n",GREEN, buf->letter, buf->x, buf->y, RESET);
		buf = buf->next;
	}
	if (buf)
		return(0);

	return (1);

}
