/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:51:48 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/07 18:01:03 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_calc(int fd)
{
	static char	*str;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	int			i;
	int			k;
	int			j;

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
		if (str[i] == '\n' && str[i + 1] == '\n')
			j++;
		else if(str[i] == '\n' && str[i + 1] == '\0')
				j++;
		i++;
	}
	close(fd);
	return (j);
}
