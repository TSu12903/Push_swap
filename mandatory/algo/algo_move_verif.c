/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move_verif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:56:38 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/06 17:40:53 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_nb_max_stack_b(t_stack *stack, t_init init)
{
	init.i = 0;
	init.k = 0;
	while (init.i < stack->size_b)
	{
		if (stack->stack_b[init.i] > stack->stack_b[init.k])
			init.k = init.i;
		init.i++;
	}
	return (init.k);
}

int	ft_nb_min_stack_b(t_stack *stack, t_init init)
{
	init.i = 0;
	init.k = 0;
	while (init.i < stack->size_b)
	{
		if (stack->stack_b[init.i] < stack->stack_b[init.k])
			init.k = init.i;
		init.i++;
	}
	return (init.k);
}

void	calculate_moves_between_b(t_stack *stack, t_init *init)
{
	init->j = 0;
	while (init->j < stack->size_b)
	{
		if (init->j - 1 != -1 && stack->stack_a[init->i] > stack->stack_b[init->j]
			&& stack->stack_a[init->i] < stack->stack_b[init->j - 1])
				calculate_moves(stack->size_b, init->j, stack);
		else if (stack->stack_a[init->i] > stack->stack_b[init->j]
			&& init->j == stack->size_b - 1)
				stack->count_move++;
		init->j++;
	}
}

int	calculate_total_moves(t_stack *stack, t_init *init)
{
	if (init->i != 0)
		calculate_moves(stack->size_a, init->i, stack); // ra or rra
	init->k = ft_nb_max_stack_b(stack, *init);
	if (stack->stack_a[init->i] > stack->stack_b[init->k]) // rb or rrb
		calculate_moves(stack->size_b, init->k, stack);
	init->j = ft_nb_min_stack_b(stack, *init);
	if (stack->stack_a[init->i] < stack->stack_b[init->j]) // rb or rrb
		calculate_moves(stack->size_b, init->k, stack);
	if (stack->stack_a[init->i] > stack->stack_b[init->j]
		&& stack->stack_a[init->i] < stack->stack_b[init->k])
		calculate_moves_between_b(stack, init);
	stack->count_move++; // push b
	return (stack->count_move);
}

void	ft_best_move(t_stack *stack, t_init *init)
{
	int	tmp;

	init->i = 0;
	stack->count_move = 0;
	stack->best_move = 0;
	init->l = 0;
	while (init->i < stack->size_a)
	{
		tmp = calculate_total_moves(stack, init);
		if (stack->best_move == 0)
			stack->best_move = tmp;
		if (stack->count_move < stack->best_move)
		{
			stack->best_move = stack->count_move;
			init->l = init->i;
		}	
		stack->count_move = 0;
		init->i++;
	}
}
