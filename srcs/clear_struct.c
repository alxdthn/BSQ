/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:57:10 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/24 16:57:14 by unicolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
