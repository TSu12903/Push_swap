/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:52:13 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/09 13:57:20 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_nb_max_stack_a(t_stack *stack, t_init init)
{
	init.i = 0;
	init.k = 0;
	while (init.i < stack->size_a)
	{
		if (stack->stack_a[init.i] >= stack->stack_a[init.k])
			init.k = init.i;
		init.i++;
	}
	return (init.k);
}

int	ft_nb_min_stack_a(t_stack *stack, t_init init)
{
	init.i = 0;
	init.k = 0;
	while (init.i < stack->size_a)
	{
		if (stack->stack_a[init.i] <= stack->stack_a[init.k])
			init.k = init.i;
		init.i++;
	}
	return (init.k);
}

void	select_moves_between_a(t_stack *stack, t_init *init)
{
	init->j = 0;
	while (init->j < stack->size_a)
	{
		if (init->j -1 != -1
			&& stack->stack_b[init->l] < stack->stack_a[init->j]
			&& stack->stack_b[init->l] > stack->stack_a[init->j - 1])
			select_rotation_a(stack->size_a, init->j, init);
		else if (stack->stack_b[init->l] > stack->stack_a[init->j]
			&& init->j == stack->size_a
			&& stack->stack_b[init->l] < stack->stack_a[0])
			init->nb_rra++;
		init->j++;
	}
}

void	determine_stack_a_moves(t_stack *stack, t_init *init)
{
	init->nb_ra = 0;
	init->nb_rb = 0;
	init->nb_rra = 0;
	init->nb_rrb = 0;
	init->min = ft_nb_min_stack_a(stack, *init);
	init->max = ft_nb_max_stack_a(stack, *init);
	if (stack->stack_b[init->l] < stack->stack_a[init->min])
		select_rotation_a(stack->size_a, init->min, init);
	if (stack->stack_b[init->l] > stack->stack_a[init->max])
		select_rotation_a(stack->size_a, init->min, init);
	if (stack->stack_b[init->l] > stack->stack_a[init->min]
		&& stack->stack_b[init->l] < stack->stack_a[init->max])
		select_moves_between_a(stack, init);
}

void	ft_move_stack_a(t_stack *stack, t_init *init)
{
	init->nb_rr = 0;
	init->nb_rrr = 0;
	determine_stack_a_moves(stack, init);
	while (init->nb_ra)
	{
		ft_rotate_a(stack, *init);
		init->nb_ra--;
	}
	while (init->nb_rra)
	{
		ft_reverse_rotate_a(stack, *init);
		init->nb_rra--;
	}
	ft_push_a(stack, init);
}
