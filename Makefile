# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mihail <mihail@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 17:41:16 by unicolle          #+#    #+#              #
#    Updated: 2019/07/24 11:53:25 by mihail           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
LIB = bsq.a

C_FLAGS = -g -Wall -Wextra -Werror
HEADER = -I includes

OBJ_DIR = obj/
SRC_DIR = srcs/
SRCS =	main.c \
		solve_bsq.c \
		read_file.c \
		validate_file.c \
		file_to_matrix.c \
		print_result.c \
		ft_puterr.c \
		ft_isdigit.c \
		ft_atoi.c \
		file_to_matrix.c

OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRCS)))

all: $(NAME)

$(NAME): $(LIB)
	gcc $(C_FLAGS) -o $(NAME) $(LIB)

$(LIB): $(OBJ)
	ar rc $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(C_FLAGS) -c $< -o $@ $(HEADER)

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(LIB)

fclean: clean
	rm -f $(NAME)

re: fclean all
