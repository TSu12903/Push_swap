/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:44:21 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/09 13:55:21 by tcybak           ###   ########.fr       */
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

void	select_moves_between_b(t_stack *stack, t_init *init)
{
	init->j = 0;
	while (init->j < stack->size_b)
	{
		if (init->j -1 != -1
			&& (stack->stack_a[init->l] > stack->stack_b[init->j]
				&& stack->stack_a[init->l] < stack->stack_b[init->j - 1]))
			select_rotation_b(stack->size_b, init->j, init);
		else if (stack->stack_a[init->l] > stack->stack_b[init->j]
			&& init->j == stack->size_b
			&& stack->stack_a[init->l] < stack->stack_b[0])
			init->nb_rrb++;
		init->j++;
	}
}

void	determine_stack_b_moves(t_stack *stack, t_init *init)
{
	init->nb_ra = 0;
	init->nb_rb = 0;
	init->nb_rra = 0;
	init->nb_rrb = 0;
	init->nb_rr = 0;
	init->nb_rrr = 0;
	if (init->l != 0)
		select_rotation_a(stack->size_a, init->l, init);
	init->max = ft_nb_max_stack_b(stack, *init);
	if (stack->stack_a[init->l] > stack->stack_b[init->max])
		select_rotation_b(stack->size_b, init->max, init);
	init->min = ft_nb_min_stack_b(stack, *init);
	if (stack->stack_a[init->l] < stack->stack_b[init->min])
		select_rotation_b(stack->size_b, init->max, init);
	if (stack->stack_a[init->l] > stack->stack_b[init->min]
		&& stack->stack_a[init->l] < stack->stack_b[init->max])
		select_moves_between_b(stack, init);
}

void	ft_execute_reverse_rotate(t_stack *stack, t_init *init)
{
	while (init->nb_rrr)
	{
		ft_reverse_rotate_a_b(stack, *init);
		init->nb_rrr--;
	}
	while (init->nb_rra)
	{
		ft_reverse_rotate_a(stack, *init);
		init->nb_rra--;
	}
	while (init->nb_rrb)
	{
		ft_reverse_rotate_b(stack, *init);
		init->nb_rrb--;
	}
}

void	ft_move_stack_b(t_stack *stack, t_init *init)
{
	determine_stack_b_moves(stack, init);
	if (init->nb_ra != 0 && init->nb_rb != 0)
		check_reverse_rr(init);
	if (init->nb_rra != 0 && init->nb_rrb != 0)
		check_reverse_rrr(init);
	while (init->nb_rr)
	{
		ft_rotate_a_b(stack, *init);
		init->nb_rr--;
	}
	while (init->nb_ra)
	{
		ft_rotate_a(stack, *init);
		init->nb_ra--;
	}
	while (init->nb_rb)
	{
		ft_rotate_b(stack, *init);
		init->nb_rb--;
	}
	ft_execute_reverse_rotate(stack, init);
	ft_push_b(stack, init);
}
