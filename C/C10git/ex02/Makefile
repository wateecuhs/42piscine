# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 13:19:11 by panger           #+#    #+#              #
#    Updated: 2023/08/24 14:11:28 by panger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/input_handling.c ./srcs/lib.c ./srcs/tail.c ./srcs/read_stdin.c ./srcs/multiple_files_handling.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS=$(SRCS:.c=.o)
NAME = ft_tail
HEADER_DIR    = includes/

all: $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:  all clean fclean re