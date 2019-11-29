/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_we_moveY.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 09:00:29 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/26 23:11:26 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_can_we_moveY(t_tetr* t, size_t y, size_t* field)
{
	if (*field - t->y - y <= 3)
		if (((t->t >> (y * 4)) & 15) !=0) 
		 return (0);
return (1);
}
