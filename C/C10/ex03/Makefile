# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: panger <panger@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 13:19:11 by panger           #+#    #+#              #
#    Updated: 2023/08/24 13:41:27 by panger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/basic_print.c ./srcs/c_option.c ./srcs/lib.c ./srcs/main.c ./srcs/lib2.c ./srcs/input_reading.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS=$(SRCS:.c=.o)
NAME = ft_hexdump
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