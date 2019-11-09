/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:30:23 by mstefani          #+#    #+#             */
/*   Updated: 2019/10/30 21:55:03 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa_b(int n)
{
	int				len;
	char			*res;
	long long int	dig;

	dig = n;
	len = ft_leni(dig);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (0);
	res[len] = '\0';
	len--;
	if (n < 0)
	{
		res[0] = '-';
		dig = -dig;
	}
	if (n / 1 == 0)
		res[0] = '0';
	while (dig != 0)
	{
		res[len] = (dig % 2) + '0';
		dig = dig / 2;
		len--;
	}
	return (res);
}
