/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:06:13 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/24 13:58:05 by mihail           ###   ########.fr       */
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
