/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:05:43 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/24 17:34:36 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solve_bsq(int fd)
{
	t_a a;

	ft_bzero(&a, sizeof(t_a));
	a.file = read_file(fd);
	if (validate_file(&a))
	{
		file_to_matrix(&a);
		find_bsq(&a);
		printf("size: %d\npos_x: %d\npos_y: %d\n", a.bsq_side_size, a.bsq_pos_x, a.bsq_pos_y);
		print_result(&a);
	}
	clear_struct(&a);
}
