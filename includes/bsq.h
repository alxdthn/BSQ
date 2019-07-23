/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unicolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:07:51 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/23 17:07:53 by unicolle         ###   ########.fr       */
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

typedef struct s_a
{
	char	*file;
	int		**matrix;
}			   t_a;

void	solve_bsq(int fd);
char	*read_file(int fd);
void	validate_file(t_a *a);

#endif