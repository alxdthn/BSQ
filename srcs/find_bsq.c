/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:02:23 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/24 18:38:13 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	get_min_and_pos(t_a *a, int x, int y)
 {
	int		min;

	if (a->matrix[y][x])
	{
		if (x + 1 >= a->symb_quantity || y + 1 >= a->str_quantity)
			min = 0;
		else
		{
			min = a->matrix[y][x + 1];
			if (a->matrix[y + 1][x + 1] < min)
				min = a->matrix[y + 1][x + 1];
			if (a->matrix[y + 1][x] < min)
				min = a->matrix[y + 1][x];
		}
		a->matrix[y][x] += min;
		if (a->matrix[y][x] >= a->bsq_side_size)
		{
			a->bsq_pos_x = x;
			a->bsq_pos_y = y;
			a->bsq_side_size = a->matrix[y][x];
		}
	}
}

void	find_bsq(t_a *a)
{
	int		x;
	int		y;

	a->bsq_pos_x = 0;
	a->bsq_pos_y = 0;
	a->bsq_side_size = 0;
	y = a->str_quantity - 1;
	while (y >= 0)
	{
		x = a->symb_quantity - 1;
		while (x >= 0)
			get_min_and_pos(a, x--, y);
		--y;
	}
	a->bsq_square_size = a->bsq_side_size * a->bsq_side_size;
}
