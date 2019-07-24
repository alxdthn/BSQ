/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:05:28 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/24 17:05:31 by unicolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_result(t_a *a)
{
	int	x;
	int	side;

	while (a->bsq_square_size-- > 0)
	{
		x = a->bsq_pos_x;
		side = a->bsq_side_size;
		while (side--)
		{
			a->map[a->bsq_pos_y * (a->symb_quantity + 1) + x++] = a->full;
			--a->bsq_square_size;
		}
		++a->bsq_pos_y;
	}
	write(1, a->map, a->map_symb_count);
}
