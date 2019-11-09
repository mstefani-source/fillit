/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:25:41 by mstefani          #+#    #+#             */
/*   Updated: 2019/10/22 12:22:44 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *st)
{
	long int	ch;
	int			sign;

	ch = 0;
	sign = 1;
	while (ft_ispace(*st))
		st++;
	if (*st == '-')
		sign = -sign;
	if (*st == '+' || *st == '-')
		st++;
	while (*st != '\0' && ft_isdigit(*st))
	{
		if ((ch == LONG_MAX / 10 && (*st - '0' > 7)) || (ch > LONG_MAX / 10))
		{
			if (sign > 0)
				return (-1);
			return (0);
		}
		ch = ch * 10 + (*st - '0');
		st++;
	}
	return (sign * ch);
}
