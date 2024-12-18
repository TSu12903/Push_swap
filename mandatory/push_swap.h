/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:58:24 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/18 19:28:08 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define NO_PRINT 0

typedef struct s_stack
{
	long	*stack_a;
	long	*stack_b;
	int		size_a;
	int		size_b;
	int		best_move;
	int		count_move;
}			t_stack;

typedef struct s_init
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	print;
	int count;
	int nb_count_size;
}		t_init;

////////////////////////////////////////
///				Utils.c				///
//////////////////////////////////////

void	ft_free(char **str);
long	*ft_one_free(long *tab1);
int		ft_strlen_long(long	*tab);

////////////////////////////////////////
///				Parsing2.c			///
//////////////////////////////////////

int		ft_verfi_twice(long *str, int num);
int ft_protect_overflow(char *str, t_init init);

////////////////////////////////////////
///				Main.c				///
//////////////////////////////////////

long	*ft_parsing(char **av, t_init *init);

////////////////////////////////////////
///				Order_s_p.c				///
//////////////////////////////////////

void	ft_swap_a(t_stack *stack, t_init *init);
void	ft_swap_b(t_stack *stack, t_init *init);
void	ft_swap_ss(t_stack *stack);
void	ft_push_b(t_stack *stack, t_init *init);
void	ft_push_a(t_stack *stack, t_init *init);

////////////////////////////////////////
///				Order_r.c			///
//////////////////////////////////////

void	ft_rotate_a(t_stack *stack, t_init init);
void	ft_rotate_b(t_stack *stack, t_init init);
void	ft_rotate_a_b(t_stack *stack, t_init init);
void	ft_reverse_rotate_a(t_stack *stack, t_init init);
void	ft_reverse_rotate_b(t_stack *stack, t_init init);

////////////////////////////////////////
///				init.c				///
//////////////////////////////////////

void	ft_init(t_init	*init);

////////////////////////////////////////
///				order_rrr.c			///
//////////////////////////////////////

void    ft_reverse_rotate_a_b(t_stack *stack, t_init init);

////////////////////////////////////////
///				algo.c				///
//////////////////////////////////////

void    ft_algo(t_stack *stack, t_init *init);

////////////////////////////////////////
///				algo_move.c			///
//////////////////////////////////////

void	ft_best_move(t_stack *stack, t_init *init);

#endif
