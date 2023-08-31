# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 13:19:11 by panger           #+#    #+#              #
#    Updated: 2023/08/24 12:23:47 by panger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/ft.c ./srcs/operations.c ./srcs/do_op.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS=$(SRCS:.c=.o)
NAME = do-op

all: $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:  all clean fclean re
