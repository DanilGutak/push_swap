# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 17:55:20 by dgutak            #+#    #+#              #
#    Updated: 2023/09/26 20:40:14 by dgutak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux 
LDFLAGS = -L./libft -lft

NAME = push_swap
LIBFT	=	./libft/libft.a
SRCS = main.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS) $(LDFLAGS) -g

.c.o:
	cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./include


clean:
	rm -f $(OBJS)
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/


re: fclean all

.PHONY: all clean fclean re
