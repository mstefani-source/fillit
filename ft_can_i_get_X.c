/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_i_get_X.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:34:47 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/03 20:56:53 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_can_i_get_X(t_tetr* candidat, t_tetr* resident, size_t x, size_t* field)
{
	int offset;
	
	if ((*field - resident->x) >= 4)
		return (1);

	offset = 4 - (*field - resident->x);
	if ((candidat->t >> x >> offset & 4369) != 0)
			return (0);
return (1);
}
