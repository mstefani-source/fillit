/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overlong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:44:38 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 16:12:40 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_overlong(long int d, int sign, char c)
{
	if (((d == (LONG_MAX / 10)) && (c - '0') > 7) || d > (LONG_MAX / 10))
	{
		if (sign > 0)
			return (-1);
		return (0);
	}
	return (0);
}
