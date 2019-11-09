/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:26:45 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/08 13:31:27 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     ft_calc_field(int num_tet)
{
    int     pre = num_tet * 4;

    while (ft_sqrt(pre) == 0)
        pre++;
    return (ft_sqrt(pre));
}
