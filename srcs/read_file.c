/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:06:13 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/23 17:06:15 by unicolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		return (i);
	}
	else
		return (0);
}

char	*ft_strjoin(char *file, char *buf)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = (char *)malloc(ft_strlen(file) + ft_strlen(buf) + 1)))
		return (NULL);
	if (file)
	{
		while (*file)
			res[i++] = *(file++);
	}
	while (*buf)
		res[i++] = *(buf++);
	res[i] = '\0';
	return (res);
}

char	*read_file(int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*file;
	int		ret;
	char	*tmp;

	file = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(file, buf)))
			return (NULL);
		free(file);
		file = tmp;
	}
	return (file);
}
