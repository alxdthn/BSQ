/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:40:45 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/23 22:06:29 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		initial_quantities(t_a *a)
{
	int		i;
	int		j;

	a->symb_quantity = 0;
	while (a->map[a->symb_quantity] && a->map[a->symb_quantity] != '\n')
		a->symb_quantity++;
	j = 0;
	while (a->map[j])
	{
		i = 0;
		while (a->map[j] && a->map[j] != '\n')
		{
			if (a->map[j] != a->empty && a->map[j] != a->obstacle)
				return (ft_puterr(0));
			++i;
			++j;
		}
		if (i != a->symb_quantity)
			return (ft_puterr(0));
		if (a->map[j])
			++j;
	}
	if ((j - a->str_quantity) / a->symb_quantity != a->str_quantity)
		return (ft_puterr(0));
	return (1);
}

int		validate_file(t_a *a)
{
	int	i;

	i = 0;
	if (!a->file)
		return (ft_puterr(0));
	while (a->file[i] && a->file[i] != '\n')
		i++;
	if (i < 4 || i > 13)
		return (ft_puterr(0));
	if (!a->file[i + 1])
		return (ft_puterr(0));
	a->map = a->file + i + 1;
	a->full = a->file[--i];
	a->obstacle = a->file[--i];
	a->empty = a->file[--i];
	a->file[i--] = '\0';
	while (i >= 0)
	{
		if (!ft_isdigit(a->file[i--]))
			return (ft_puterr(0));
	}
	a->str_quantity = ft_atoi(a->file);
	if (a->str_quantity < 0)
		return (ft_puterr(0));
	return (initial_quantities(a));
}
