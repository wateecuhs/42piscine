# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 09:45:06 by panger            #+#    #+#              #
#    Updated: 2023/08/22 15:23:21 by panger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=gcc
FLAGS=-Wall -Wextra -Werror
SRCS=./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS=$(SRCS:.c=.o)
HEADER_DIR    = includes/

all : $(NAME)

re: fclean all	

%.o : %.c
	$(CC) -c $(FLAGS) -I $(HEADER_DIR) -c $< -o $@

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)