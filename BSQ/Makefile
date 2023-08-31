# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 13:19:11 by panger           #+#    #+#              #
#    Updated: 2023/08/27 14:34:35 by brappo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/main.c ./srcs/map_to_arr.c ./srcs/read_stdin.c ./srcs/lib.c ./srcs/ft_strdup.c ./srcs/solve.c ./srcs/solve_functions.c ./srcs/compare_len_functions.c ./srcs/ft_split.c ./srcs/ft_strict_atoi.c ./srcs/read_map_file.c ./srcs/valid_args.c ./srcs/valid_args_functions.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS=$(SRCS:.c=.o)
NAME = bsq
HEADER_DIR = ./includes/

all: $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) -fsanitize=address -g -I $(HEADER_DIR) -c $< -o $@

$(NAME): $(OBJS) | $(HEADER_DIR)
	$(CC) -fsanitize=address -g -I $(HEADER_DIR) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:  all clean fclean re
