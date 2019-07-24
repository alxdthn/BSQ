#include "bsq.h"

void	clear_struct(t_a *a)
{
	int		i;

	free(a->file);
	i = 0;
	if (a->matrix)
		while (a->matrix[i])
			free(a->matrix[i++]);
	free(a->matrix);
}
