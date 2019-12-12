/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:37:09 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/12 18:37:23 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void ft_free_list(t_tetr *result)
{
	while (result)
	{
		free (result);
		result = result->next;
	}
	free (result);
}
