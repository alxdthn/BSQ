/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:07:51 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/23 19:37:50 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUFF_SIZE 1024
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_a
{
	char		*file;
	char		*map;
	int			**matrix;
	int			str_quantity;
	int			symb_quantity;
	char		empty;
	char		obstacle;
	char		full;
}				t_a;

void			solve_bsq(int fd);
char			*read_file(int fd);
int				validate_file(t_a *a);
int				ft_puterr(int ret);

#endif