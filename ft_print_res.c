/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:09:54 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/17 19:06:34 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_res(t_tetr* result)
{
	printf("tetra ch x y\n");
	while (result)
	{
		printf("%llu %c  %zu %zu\n",result->tetr, result->letter, result->x, result->y);
		result = result->next;
	}
}
