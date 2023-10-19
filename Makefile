# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/31 17:55:20 by dgutak            #+#    #+#              #
#    Updated: 2023/10/19 11:37:07 by dgutak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft -lft

NAME = push_swap
LIBFT	=	./libft/libft.a
SRCS = main.c utils.c error.c sort.c ./funcs/rrr.c ./funcs/rr.c ./funcs/ss.c ./funcs/p.c push_a.c push_b.c sort_small.c
BSRCS = utils.c error.c sort.c ./funcs/rrr.c ./funcs/rr.c ./funcs/ss.c ./funcs/p.c push_a.c push_b.c sort_small.c checker.c get_next_line.c  get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS) $(LDFLAGS) 

.c.o:
	cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./include -I ./libft


clean:
	rm -f $(OBJS) $(BOBJS)
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME) checker
	rm -f ./libft/libft.a 


re: fclean all


bonus: $(BOBJS)
	make -C ./libft/
	$(CC) $(CFLAGS) $(LIBFT) -o checker $(BOBJS) $(LDFLAGS) -g

.PHONY: all clean fclean re
