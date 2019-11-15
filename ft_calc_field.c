/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:26:45 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/15 19:16:54 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_calc_field(int num_tet)
{
	int	pre;

	pre = num_tet * 4;
	while (ft_sqrt(pre) == 0)
		pre++;
	return (ft_sqrt(pre));
}
