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

SRCS = itoa.c main.c check_dict.c is_printable.c ft_strdup.c ft_atoi_first3.c ft_size.c dict_to_str.c lib.c put_nbr.c split_number.c read_stdin.c lookupdict.c check_dict2.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS=$(SRCS:.c=.o)
NAME = rush-02
HEADER_DIR = ./

all: $(NAME)

%.o : %.c
	$(CC) -c $(CFLAGS)  -I $(HEADER_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) -fsanitize=address -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:  all clean fclean re
