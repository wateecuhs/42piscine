# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 13:19:11 by panger           #+#    #+#              #
#    Updated: 2023/08/24 15:12:55 by panger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/display_file.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS=$(SRCS:.c=.o)
NAME = ft_display_file

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