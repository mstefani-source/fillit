/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:51:48 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/15 19:14:34 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_calc(int fd)
{
	char		*str;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	int			i;
	size_t		j;

	j = 0;
	i = 0;
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	str = ft_strdup(buf);

	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			j++;
		else if (str[i] == '\n' && str[i + 1] == '\0')
			j++;
		i++;
	}
	ft_memdel((void*)&str);
	close(fd);
	return (j);
}
