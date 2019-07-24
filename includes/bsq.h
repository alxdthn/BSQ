/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:07:51 by unicolle          #+#    #+#             */
/*   Updated: 2019/07/24 15:12:49 by mihail           ###   ########.fr       */
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
	int			map_symb_count;
	int			bsq_pos_x;
	int			bsq_pos_y;
	int			bsq_side_size;
	int			bsq_square_size;
}				t_a;

void			solve_bsq(int fd);
char			*read_file(int fd);
int				validate_file(t_a *a);
void			find_bsq(t_a *a);
void			file_to_matrix(t_a *a);
void			print_matrix(t_a *a);
void			find_bsq(t_a *a);
void			print_result(t_a *a);
void			clear_struct(t_a *a);
int				ft_puterr(int ret);
int				ft_atoi(char *str);
int				ft_isdigit(char c);
void			ft_bzero(void *src, size_t size);
size_t			ft_strlen(char *str);
char			*ft_strjoin(char *str1, char *str2);


char	*fast_read_file(int fd);

#endif