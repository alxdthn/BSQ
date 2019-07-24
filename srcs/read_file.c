/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:34:45 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/24 21:34:49 by unicolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*read_file(int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*file;
	int		ret;
	char	*tmp;

	file = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(file, buf)))
			return (NULL);
		free(file);
		file = tmp;
	}
	return (file);
}
