/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:53:43 by skale             #+#    #+#             */
/*   Updated: 2019/11/21 19:07:20 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		print_res(t_tetr *lst, int dlina)
{
	long long unsigned int	digits;
	int						tetr_num;
	int						pryg;
	int						i;
	char					res[dlina * dlina];

	i = 0;
	tetr_num = 0;
	res[dlina * dlina] = '\0';
	while (i < (dlina * dlina))
	{
		res[i] = '.';
		i++;
	}
	while (ft_l(lst, tetr_num))
	{
		i = ft_l(lst, tetr_num)->x + (ft_l(lst, tetr_num)->y * dlina);
		digits = 0b1000000000000000;
		pryg = 0;
		while (digits > 0)
		{
			if (ft_l(lst, tetr_num)->t >= digits && digits != 0)
			{
				ft_l(lst, tetr_num)->t = ft_l(lst, tetr_num)->t - digits;
				digits = digits >> 1;
				res[i] = ft_l(lst, tetr_num)->letter;
			}
			else
				digits = digits >> 1;
			i++;
			if (pryg == 3)
			{
				i = i + dlina - 4;
				pryg = 0;
			}
			pryg++;
		}
		tetr_num++;
	}
	i = 0;
	while (res[i] != '\0')
	{
		if (i % dlina == 0 && i != 0)
			write(1, "\n", 1);
		write(1, &res[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);

}
