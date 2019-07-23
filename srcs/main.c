/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:05:13 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/23 19:33:13 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int ac, char **av)
{
	int	fd;
	int i;

	i = 0;
	if (ac == 1)
		solve_bsq(0);
	else
	{
		while (i++ < ac - 1)
		{
			if ((fd = open(av[i], O_RDONLY)) < 3)
				ft_puterr(0);
			else
				solve_bsq(fd);
			close(fd);
			if (i < ac - 1)
				write (1, "\n", 1);
		}
	}
	return (0);
}
