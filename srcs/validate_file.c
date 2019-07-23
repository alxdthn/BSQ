/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:40:45 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/23 19:37:30 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_atoi(char *str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	result = result * sign;
	return (result);
}

void	initial_quantities(t_a *a, int i, int provided_str_quantity)
{
	int		j;

	j = 0;
	while (a->file[i] != '\n')
	{
		i++;
		j++;
	}
	a->symb_quantity = j;
	i = 0;
	while (*a->file)
	{
		if (*a->file == '\n')
			i++;
		a->file++;
	}
	a->str_quantity = i - 1;
	if ((a->str_quantity != provided_str_quantity))
		printf("%s\n", "MAP ERROR");
}

int		validate_file(t_a *a)
{
	int		i;
	int		provided_str_quantity;

	i = 0;
	while (a->file[i] != '\n')
		i++;
	if (i < 4 || i > 13)
		return (ft_puterr(1));
	a->full = a->file[i - 1];
	a->obstacle = a->file[i - 2];
	a->empty = a->file[i - 3];
	a->file[i - 3] = '\0';
	provided_str_quantity = ft_atoi(a->file);
	initial_quantities(a, i + 1, provided_str_quantity);
}
