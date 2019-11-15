/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:48:09 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/13 16:54:49 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_list_test(int tetr1, int tetr2)
{
	int		i = 0;
	if ((tetr1 & tetr2) == 0)
			{
				printf("сдвинули на %d\n", i);
				return ;
			}
	i++;
	ft_list_test(tetr1 << 1, tetr2);
	return ;
}
