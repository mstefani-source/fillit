/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 23:01:46 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 22:44:02 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_ispace(char ch)
{
	if (ch == ' ')
		return (1);
	if (ch == '\t')
		return (1);
	if (ch == '\n')
		return (1);
	if (ch == '\v')
		return (1);
	if (ch == '\r')
		return (1);
	if (ch == '\f')
		return (1);
	return (0);
}