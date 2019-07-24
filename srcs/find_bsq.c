#include "bsq.h"

void	get_min_and_pos(t_a *a, int x, int y)
{
	int		min;

	if (a->matrix[y][x])
	{
		min = a->matrix[y][x + 1];
		if (a->matrix[y + 1][x + 1] < min)
			min = a->matrix[y + 1][x + 1];
		if (a->matrix[y + 1][x] < min)
			min = a->matrix[y + 1][x];
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
	y = a->symb_quantity - 2;
	while (y >= 0)
	{
		x = a->str_quantity - 2;
		while (x >= 0)
			get_min_and_pos(a, x--, y);
		--y;
	}
	a->bsq_square_size = a->bsq_side_size * a->bsq_side_size;
}
