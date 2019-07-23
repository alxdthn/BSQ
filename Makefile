# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mihail <mihail@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 17:41:16 by unicolle          #+#    #+#              #
#    Updated: 2019/07/23 19:14:32 by mihail           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
LIB = bsq.a

C_FLAGS = -Wall -Wextra -Werror
HEADER = -I includes

OBJ_DIR = obj/
SRC_DIR = srcs/
SRCS =	main.c \
		solve_bsq.c \
		read_file.c \
		validate_file.c \
		ft_puterr.c

OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRCS)))

all: $(NAME)

$(NAME): $(LIB)
	gcc -o $(NAME) $(LIB)

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
