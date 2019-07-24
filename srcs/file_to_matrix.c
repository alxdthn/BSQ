/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:59:37 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/24 16:59:46 by unicolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	file_to_matrix(t_a *a)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	if (!(a->matrix = (int **)malloc(sizeof(int *) * (a->str_quantity + 1))))
		exit(1);
	a->matrix[a->str_quantity] = NULL;
	while (a->map[k])
	{
		j = 0;
		if (!(a->matrix[i] = (int *)malloc(sizeof(int) * a->symb_quantity)))
			exit(1);
		while (a->map[k] != '\n')
		{
			a->matrix[i][j] = (a->map[k] == a->empty) ? 1 : 0;
			++j;
			++k;
		}
		++k;
		++i;
	}
}
