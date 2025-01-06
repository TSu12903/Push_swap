/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:44:21 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/06 12:27:40 by tcybak           ###   ########.fr       */
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

void	ft_move(t_stack *stack, t_init *init)
{
	init->nb_ra = 0;
	init->nb_rb = 0;
	init->nb_rra = 0;
	init->nb_rrb = 0;
	if (init->l != 0)
		select_rotation_a(stack, init); // ra or rra
	init->k = ft_nb_max_stack_b(stack, *init);
	if (stack->stack_a[init->l] > stack->stack_b[init->k]) // rb or rrb
		select_rotation_b(stack, init);
	init->j = ft_nb_min_stack_b(stack, *init);
	if (stack->stack_a[init->l] < stack->stack_b[init->j]) // rb or rrb
		select_rotation_b(stack, init);
	if (stack->stack_a[init->l] > stack->stack_b[init->j]
		&& stack->stack_a[init->l] < stack->stack_b[init->k])
		//calculate_moves_between(stack, init);
	ft_push_b(stack, init); // push b
}
