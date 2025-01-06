/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:58:24 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/06 16:12:39 by tcybak           ###   ########.fr       */
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
	int	count;
	int	nb_count_size;
	int	stop_move_a;
	int	tree;
	int	nb_ra;
	int	nb_rb;
	int	nb_rra;
	int	nb_rrb;
	int	nb_rrr;
	int	nb_rr;
}		t_init;

////////////////////////////////////////
///				Utils_parsing.c		///
//////////////////////////////////////

void	ft_free(char **str);
long	*ft_one_free(long *tab1);

////////////////////////////////////////
///				Utils_algo.c		///
//////////////////////////////////////

void	calculate_moves(int stack1, int far , t_stack *stack);
void	select_rotation_b(int stack, int far, t_init *init);
int		check_reverse(int ra, int rb, int rr);
void	select_rotation_a(int stack, int far, t_init *init);

////////////////////////////////////////
///				Parsing2.c			///
//////////////////////////////////////

int		ft_verfi_twice(long *str, int num);

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

void	ft_reverse_rotate_a_b(t_stack *stack, t_init init);

////////////////////////////////////////
///				algo.c				///
//////////////////////////////////////

void	ft_algo(t_stack *stack, t_init *init);

////////////////////////////////////////
///			algo_move_verfif.c		///
//////////////////////////////////////
int		ft_nb_min_stack_b(t_stack *stack, t_init init);
int		ft_nb_max_stack_b(t_stack *stack, t_init init);
void	ft_best_move(t_stack *stack, t_init *init);

////////////////////////////////////////
///			algo_move.c				///
//////////////////////////////////////

void	ft_less_tree(t_stack *stack, t_init *init);
void	ft_move_stack_b(t_stack *stack, t_init *init);



//////////////////////////////////////

void	print(t_stack *stack ,t_init init);
#endif