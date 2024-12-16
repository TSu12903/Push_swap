# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 10:12:04 by tcybak            #+#    #+#              #
#    Updated: 2024/12/16 16:13:12 by tcybak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJDIR := ./obj
CC := cc
CFLAGS := -Wall -Werror -Wextra -g
NAME := push_swap
LIBFT := libft/libft.a
LIB := libft
SRC := mandatory/parsing/parsing1.c \
       mandatory/parsing/parsing2.c \
       mandatory/order/order_s_p.c \
       mandatory/order/order_r.c \
       mandatory/main.c \
       mandatory/utils/utils.c \
       mandatory/order/order_rrr.c \
       mandatory/init/init.c \
       mandatory/algo/algo.c

OBJ := $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@) # Automatically create subdirectories
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIB) clean
	
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB) fclean

re: fclean all