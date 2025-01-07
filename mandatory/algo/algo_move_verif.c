/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move_verif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:56:38 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/07 17:59:56 by tcybak           ###   ########.fr       */
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
			{
				stack->count_move++;
			}
		init->j++;

	}
}

int	calculate_total_moves(t_stack *stack, t_init *init)
{
	if (init->i != 0)
	{
		calculate_moves(stack->size_a, init->i, stack); // ra or rra
		// ft_printf("Here 1 number = %d len_a = %d\n", stack->stack_a[init->i], stack->count_move);
	}
	init->max = ft_nb_max_stack_b(stack, *init);
	if (stack->stack_a[init->i] > stack->stack_b[init->max])
	{ // rb or rrb
		calculate_moves(stack->size_b, init->max, stack);
		// ft_printf("Here 2 number = %d total = %d len_a = %d len_b = %d\n", stack->stack_a[init->i], stack->count_move, tmp, stack->count_move - tmp);
	}
	init->min = ft_nb_min_stack_b(stack, *init);
	if (stack->stack_a[init->i] < stack->stack_b[init->min]) // rb or rrb
	{
		calculate_moves(stack->size_b, init->max, stack);
		// ft_printf("Here 3 number = %d total = %d len_a = %d len_b = %d\n", stack->stack_a[init->i], stack->count_move, tmp, stack->count_move - tmp);
	}
	if (stack->stack_a[init->i] > stack->stack_b[init->min]
		&& stack->stack_a[init->i] < stack->stack_b[init->max])
	{
		calculate_moves_between_b(stack, init);
		// ft_printf("Here 4 number = %d total = %d len_a = %d len_b = %d\n", stack->stack_a[init->i], stack->count_move, tmp, stack->count_move - tmp);
	}
	stack->count_move++; // push b
	// ft_printf("final number = %d mouve = %d\n", stack->stack_a[init->i], stack->count_move);
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
	// ft_printf("\nnumber = %d best mouve = %d\n", stack->stack_a[init->l], stack->best_move);
}
