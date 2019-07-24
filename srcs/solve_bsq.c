/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:05:43 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/24 12:05:54 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solve_bsq(int fd)
{
	t_a a;

	a.file = read_file(fd);
	if (validate_file(&a))
	{
		//file_to_matrix(&a);
		//print_matrix(&a);
		a.bsq_pos_x = 0;
		a.bsq_pos_y = 0;
		a.bsq_side_size = 4;
		a.bsq_square_size = a.bsq_side_size * a.bsq_side_size;
		print_result(&a);
	}
}
