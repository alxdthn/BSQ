void	file_to_matrix(t_a *a)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	if (!(a->matrix = (int **)malloc(sizeof(int *) * (str_quantity + 1))))
		exit (1);
	while (a->map[k])
	{
		j = 0;
		if (!(a->matrix[i] = (int *)malloc(sizeof(int) * symb_quantity)))
			exit (1);
		while (a->map[k] != '\n')
		{
			if (a->map[k] == empty)
				a->matrix[i][j] = 1;
			else
				a->matrix[i][j] == 0;
			++j;
			++k;
		}
		++k;
		++i;
	}
}