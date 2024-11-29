# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcybak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 10:12:04 by tcybak            #+#    #+#              #
#    Updated: 2024/10/08 10:12:40 by tcybak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g
NAME= push_swap
LIBFT = libft/libft.a
LIB = libft
SRC= parsing.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -c $(SRC) $(CFLAGS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB)
	
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIB) clean
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB) fclean

re: fclean all
