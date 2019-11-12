/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:09:54 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/11 22:39:35 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_res(t_tetr* result)
{
	while (result)
	{
		printf("%d %c\n",result->tetr, result->letter);
		result = result->next;
//		sleep (1);
	}
}
