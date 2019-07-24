#include "bsq.h"

void	find_bsq(t_a *a)
{
	a->bsq_pos_x = 0;
	a->bsq_pos_y = 0;
	a->bsq_side_size = 3;
	a->bsq_square_size = a->bsq_side_size * a->bsq_side_size;
}
