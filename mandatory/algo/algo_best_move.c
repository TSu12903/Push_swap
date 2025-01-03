/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:44:21 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/03 20:38:55 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_less_tree(t_stack *stack, t_init *init)
{
	init->tree = 0;
	if (stack->size_a == 3)
	{
		if (stack->stack_a[init->tree] > stack->stack_a[init->tree + 1] 
			&& stack->stack_a[init->tree] < stack->stack_a[init->tree + 2])
			ft_swap_a(stack, init);
		else if (stack->stack_a[init->tree] > stack->stack_a[init->tree + 2] 
			&& stack->stack_a[init->tree + 2] > stack->stack_a[init->tree + 1])
			ft_rotate_a(stack, *init);
		else if (stack->stack_a[init->tree] > stack->stack_a[init->tree + 1] 
			&& stack->stack_a[init->tree + 1] > stack->stack_a[init->tree + 2])
		{
			ft_swap_a(stack, init);
			ft_reverse_rotate_a(stack, *init);
		}
		else if (stack->stack_a[init->tree + 1] > stack->stack_a[init->tree + 2] 
			&& stack->stack_a[init->tree + 2] > stack->stack_a[init->tree])
		{
			ft_reverse_rotate_a(stack, *init);
			ft_swap_a(stack, init);
		}
		else if (stack->stack_a[init->tree + 1] > stack->stack_a[init->tree] 
			&& stack->stack_a[init->tree] > stack->stack_a[init->tree + 2])
			ft_reverse_rotate_a(stack, *init);
	}
}
