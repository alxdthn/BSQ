void	file_to_matrix(t_a *a)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	if (!(a->matrix = (int **)malloc(sizeof(int) * str_quantity * symb_quantity)))
		exit (1);
	while (*a->map)
	{
		j = 0;
		a->matrix[i] = (int *)malloc(sizeof(int) * symb_quantity);
		while (*a->map != '\n')
		{
			a->matrix[i][j] = *(a->map++);
			j++;
		}
		i++;
		a->map++;
	}
}