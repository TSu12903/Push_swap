/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:56:38 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/18 20:28:41 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_nb_max_stack_b(t_stack *stack, t_init init)
{
	init.i= 0;
	init.i= 0;
	while (init.i < stack->size_b)
	{
		if (stack->stack_b[init.i] > stack->stack_b[init.k])
			init.k = init.i;
		init.i++;
	}
	ft_printf("-+-+-+-+-%d\n", init.k);
	return (init.k);
}

void   ft_count_move(t_stack *stack, t_init *init)
{
	if (stack->stack_a[init->i] != 0)
		stack->count_move += init->i; // ra or rra
	if (stack->stack_a[init->i] < stack->stack_b[0])
	{
		init->k = ft_nb_max_stack_b(stack, *init);
		if (stack->stack_b[0] < stack->stack_b[init->k]) // rb or rrb
		{
			if ( (init->k - stack->size_b) < stack->size_b / 2)
				stack->count_move += init->k - stack->size_b;
			else
				stack->count_move += init->k;
		}
	}
	stack->count_move++; // push b
}

void	ft_best_move(t_stack *stack, t_init *init)
{
	init->i = 0;
	stack->count_move = 0;
	stack->best_move = 100000000;
	init->l = 0;
	while(init->i < stack->size_a)
	{

		ft_count_move(stack, init);
		if (stack->count_move < stack->best_move)
		{
			stack->best_move = stack->count_move;
			init->l = init->i;
		}	
		stack->count_move = 0;
		init->i++;
	}
}