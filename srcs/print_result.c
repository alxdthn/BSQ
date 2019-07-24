#include "bsq.h"

void	print_result(t_a *a)
{
	int		x;
	int		y;
	int		side;

	y = a->bsq_pos_y;
	while (--a->bsq_square_size)
	{
		x = a->bsq_pos_x;
		side = a->bsq_side_size;
		while (--side)
			a->map[y * a->str_quantity + x--] = a->full;
		--y;
	}
	write(1, a->map, a->map_symb_count);
}
