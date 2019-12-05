/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_we_moveY.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 09:00:29 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/04 21:06:42 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_can_we_moveY(t_tetr* t, size_t y, size_t* field)
{
	if (*field - t->y > 4)
		return(1);
	if (*field - 1 - t->y <= 3)
		if (((t->t >> ((4 - (*field - t->y - y)) * 4)) & 15) !=0) 
		 return (0);
return (1);
}
