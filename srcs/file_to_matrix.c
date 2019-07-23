#include "bsq.h"

void	file_to_matrix(t_a *a)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	if (!(a->matrix = (int **)malloc(sizeof(int *) * (a->str_quantity + 1))))
		exit (1);
	while (a->map[k])
	{
		j = 0;
		if (!(a->matrix[i] = (int *)malloc(sizeof(int) * a->symb_quantity)))
			exit (1);
		while (a->map[k] != '\n')
		{
			if (a->map[k] == a->empty)
				a->matrix[i][j] = 1;
			else
				a->matrix[i][j] = 0;
			++j;
			++k;
		}
		++k;
		++i;
	}
}

void	print_matrix(t_a *a)
{
	int i;
	int j;

	i = 0;
	while (a->matrix[i])
	{
		j = 0;
		while (j < a->symb_quantity)
			printf("%d", a->matrix[i][j++]);
		write(1, "\n", 1);
		i++;
	}
}