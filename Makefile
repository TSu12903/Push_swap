# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 10:12:04 by tcybak            #+#    #+#              #
#    Updated: 2024/12/16 11:37:42 by tcybak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g
NAME = push_swap
LIBFT = libft/libft.a
LIB = libft
SRC=  	mandatory/parsing/parsing1.c \
	mandatory/parsing/parsing2.c \
	mandatory/order/order_s_p.c \
	mandatory/order/order_r.c \
	mandatory/main.c \
	mandatory/utils/utils.c \
	mandatory/order/order_rrr.c \
	mandatory/init/init.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -c $(SRC) $(CFLAGS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIB) clean
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB) fclean

re: fclean all
