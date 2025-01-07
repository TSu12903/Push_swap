# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 10:12:04 by tcybak            #+#    #+#              #
#    Updated: 2025/01/07 10:08:55 by tcybak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR	:= ./mandatory
OBJDIR := ./obj
CC := cc
CFLAGS := -Wall -Werror -Wextra -g
NAME := push_swap
LIBFT := libft/libft.a
LIB := libft
SRC := parsing/parsing1.c \
	   parsing/parsing2.c \
	   order/order_s_p.c \
	   order/order_r.c \
	   main.c \
	   utils/utils_parsing.c \
	   utils/utils_algo.c \
	   order/order_rrr.c \
	   init/init.c \
	   algo/algo.c	\
	   algo/algo_move_verif.c \
	   algo/algo_move_stack_b.c \
	   algo/algo_move_stack_a.c \

OBJ := $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIB) -s

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIB) clean
	
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB) fclean
	@echo Good Bebou

re: fclean all