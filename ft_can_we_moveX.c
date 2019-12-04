/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_we_moveX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 09:00:29 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/03 20:56:43 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_can_we_moveX(t_tetr* t, size_t x, size_t* field)
{
	int offset;
	
	if (*field - t->x >= 4)
		return(1);
	offset = 3 - (*field - 1 - t->x);
	if ((*field - 1 - t->x) <= 3) 
		if ((t->t >> x >> offset & 4369) != 0)
			return (0);
return (1);
}
