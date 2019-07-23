/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:40:45 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/23 17:40:47 by unicolle         ###   ########.fr       */
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
	int		str_quantity;
	int		symb_quantity;
	int		j;

	j = 0;
	while (a->file[i] != '\n')
	{
		i++;
		j++;
	}
	symb_quantity = j;
	i = 0;
	while (*a->file)
	{
		if (*a->file == '\n')
			i++;
		a->file++;
	}
	str_quantity = i - 1;
	if ((str_quantity != provided_str_quantity))
		printf("%s\n", "MAP ERROR");
	printf("%d , %d\n", symb_quantity, str_quantity);
}

void	validate_file(t_a *a)
{
	int		i;
	char	full;
	char	empty;
	char	obstacle;
	int		provided_str_quantity;

	i = 0;
	while (a->file[i] != '\n')
		i++;
	if (i < 4 || i > 13)
		printf("%s\n", "LEGEND ERROR");
	printf("%s\n", a->file);
	full = a->file[i - 1];
	obstacle = a->file[i - 2];
	empty = a->file[i - 3];
	a->file[i - 3] = '\0';
	provided_str_quantity = ft_atoi(a->file);
	a->file[i - 3] = empty;
	initial_quantities(a, i + 1, provided_str_quantity);
	printf("%c , %c , %c\n", empty, obstacle, full);
}











