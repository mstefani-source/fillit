/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:45:10 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 16:14:02 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr(char const *st)
{
	char	*res;

	if (st == 0)
		return ;
	res = (char*)st;
	while (*res != '\0')
	{
		ft_putchar(*res);
		res++;
	}
}
