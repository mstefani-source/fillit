/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:04:24 by skale             #+#    #+#             */
/*   Updated: 2019/11/15 19:26:37 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_up_left(int k)
{
	while (k < 0b1000000000000)
		k = k << 4;
	while ((0b1000100010001000 & k) == 0)
		k = k << 1;
	return (k);
}

int		ft_error(int k)
{
	if (k != 34952 && k != 61440 && k != 52224 && k != 35008)
	{
		if (k != 50240 && k != 59392 && k != 11776 && k != 51328)
		{
			if (k != 17600 && k != 36352 && k != 57856 && k != 35904)
			{
				if (k != 27648 && k != 19584 && k != 50688 && k != 19968)
				{
					if (k != 19520 && k != 35968 && k != 58368)
					{
						write(1, "error\n", 6);
						return (-1);
					}
				}
			}
		}
	}
	return (1);
}

unsigned int		*ft_makeup(int fd)
{
	static char		*str;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	int				i;
	unsigned int	*new;
	int				k;
	int				j;

	i = 0;
	j = 0;
	k = 0;
	if (str == NULL)
		str = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_join_and_free(&str, buf);
	}
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			str[i] = '0';
		if (str[i] == '#')
			str[i] = '1';
		if (str[i] == '\n' && str[i + 1] == '\n')
			j++;
		i++;
	}
	if (!(new = (unsigned int*)malloc(sizeof(unsigned int) * j)))
	{
		free (new);
		return (0);
	}
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			new[j] = ft_up_left(k);
			if (ft_error(new[j]) < 0)
			{
				printf("invalid file\n");
				return (NULL);
			}
			j++;
			k = 0;
		}
		if (str[i] != '\n')
			k = k * 2 + (str[i] - '0');
		i++;
	}
	close(fd);
	return (new);
}
