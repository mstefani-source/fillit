/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:35:20 by mstefani          #+#    #+#             */
/*   Updated: 2019/10/24 20:46:57 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int 	ft_atoi(char *s);
int		ft_strlen(char *s);

char 	to_lower(char c)
{
	if (c >= 'A' && c <= 'F')
		return(c + 'a' - 'A');
	return (c);
}

int		ft_get_digit(char c, int rate)
{
	int max_dig = 0;

	if (rate >= 0 && rate <= 10)
		max_dig = rate + '0';
	else 
		max_dig = rate - 10 + 'a';

	if (c >= '0' && c <= '9' && c <= max_dig)
		return (c - '0');
			else if (c >= 'a' && c <= 'f' && c <= max_dig)
				return (c + 10 - 'a');
	return (-1);
}

int 	ft_atoi_base(char *s, int rate)
{
	int i = 0;
	int sign = 1;
	int len = 0;
	int	res = 0;
	int dig = 0;

	len = ft_strlen(s);
		
	if (s[i] == '-')
	{
		sign = -1;
		len--;
		i++;
	}
	while (len--)
	{
		s[i] = to_lower(s[i]);
		dig = ft_get_digit(s[i], rate);
		res = res * rate + dig;
		i++;
	}
	return(res * sign);
}

int 	main(int argc, char **argv)
{
	int rate;
	int ft_ab;

	if (argc != 3)
	{
		printf("need 2 args\n");
		return (0);
	}
	rate = ft_atoi(argv[2]);
	if (rate < 0)
	{
		printf("not valid rate\n");
			return (0);
	}
	ft_ab = ft_atoi_base(argv[1], rate);
	printf("ft_atoi_base = %d\n", ft_ab);
	return (0);
}
