/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:16 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/13 17:24:41 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	unsigned int n = ((base == 10 && value < 0) ? -value : (unsigned int)value);
	int i = 0;

	if (value == 0 || (value < 0 && base == 10))
		++i;
	while (n != 0)
	{
		n /= base;
		++i;
	}

	char *out = malloc(sizeof(char) * (i + 1));
	char hex_digits[] = "0123456789ABCDEF";
	out[i] = '\0';
	if (value < 0 && base == 10)
		out[0] = '-';
	if (value == 0)
		out[0] = '0';
	n = ((base == 10 && value < 0) ? -value : (unsigned int)value);
	while (n != 0)
	{
		--i;
		out[i] = hex_digits[n % base];
		n /= base;
	}
	return (out);
}
