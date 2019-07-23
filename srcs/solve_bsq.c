/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:05:43 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/23 19:09:11 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solve_bsq(int fd)
{
	t_a a;

	a.file = read_file(fd);
//	if (validate_file(&a))
//	{
	file_to_matrix(&a);
	print_matrix(&a);
}
