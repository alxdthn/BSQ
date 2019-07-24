/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:35:03 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/24 21:35:07 by unicolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solve_bsq(int fd)
{
	t_a a;

	ft_bzero(&a, sizeof(t_a));
	a.file = read_file(fd);
	a.symb_quantity = 0;
	if (validate_file(&a))
	{
		file_to_matrix(&a);
		find_bsq(&a);
		print_result(&a);
	}
	clear_struct(&a);
}
