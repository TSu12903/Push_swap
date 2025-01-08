/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:44:21 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/08 17:16:01 by tcybak           ###   ########.fr       */
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
		if (init->j + 1 != stack->size_b + 1 && stack->stack_a[init->l] < stack->stack_b[init->j]
			&& stack->stack_a[init->l] > stack->stack_b[init->j + 1]
					&& (stack->stack_a[init->l] < stack->stack_b[0] && stack->stack_a[init->l] > stack->stack_b[1]
						&& ((stack->stack_b[init->j] != stack->stack_b[init->min])
						|| (stack->stack_b[init->j] != stack->stack_b[init->max]))))
			{
				select_rotation_b(stack->size_b, init->j + 1, init);
//				ft_printf("B HERE4.1 rb = %d, rrb = %d number = %d \n", init->nb_rb, init->nb_rrb, stack->stack_b[init->j]);
			}
		else if (stack->stack_a[init->l] > stack->stack_b[init->j]
			&& init->j == stack->size_b && stack->stack_a[init->l] < stack->stack_b[0])
			{
				init->nb_rrb++;
//				ft_printf("B HERE4.2 rb = %d, rrb = %d number = %d \n", init->nb_rb, init->nb_rrb, stack->stack_b[init->j]);
			}
		else if (stack->stack_a[init->l] > stack->stack_b[0]
			&& init->j == stack->size_b && stack->stack_a[init->l] < stack->stack_b[init->j])
			{
				init->nb_rb++;
				// ft_printf("B HERE4.2 rb = %d, rrb = %d number = %d \n", init->nb_rb, init->nb_rrb, stack->stack_b[init->j]);
			}
		init->j++;
	}
}

void	determine_stack_b_moves(t_stack *stack, t_init *init)
{
	init->nb_ra = 0;
	init->nb_rb = 0;
	init->nb_rra = 0;
	init->nb_rrb = 0;
	// ft_printf("number stack A = %d\n" ,stack->stack_a[init->l]);
	if (init->l != 0)
	{
		select_rotation_a(stack->size_a, init->l, init); // ra or rra
		//  ft_printf("B HERE1\n");
	}
	init->max = ft_nb_max_stack_b(stack, *init);
	if (stack->stack_a[init->l] > stack->stack_b[init->max])
	{ // rb or rrb
		select_rotation_b(stack->size_b, init->max, init);
		// ft_printf("B HERE2\n");
	}
	init->min = ft_nb_min_stack_b(stack, *init);
	if (stack->stack_a[init->l] < stack->stack_b[init->min])
	{ // rb or rrb
		select_rotation_b(stack->size_b, init->max, init);
		// ft_printf("B HERE3\n");
	}
	if (stack->stack_a[init->l] > stack->stack_b[init->min]
		&& stack->stack_a[init->l] < stack->stack_b[init->max])
	{
		select_moves_between_b(stack, init);
		// ft_printf("B HERE4\n");
	}
}
void	ft_move_stack_b(t_stack *stack, t_init *init)
{
	init->nb_rr = 0;
	init->nb_rrr = 0;
	determine_stack_b_moves(stack, init);
	// ft_printf("nb_ra %d\n", init->nb_ra);
	// ft_printf("nb_rra %d\n", init->nb_rra);
	// ft_printf("nb_rb %d\n", init->nb_rb);
	// ft_printf("nb_rrb %d\n", init->nb_rrb);
	if (init->nb_ra != 0 && init->nb_rb != 0)
		check_reverse_rr(init);
	if (init->nb_rra != 0 && init->nb_rrb != 0)
		check_reverse_rrr(init);
	while (init->nb_rr)
	{
		ft_rotate_a_b(stack, *init);
		init->nb_rr--;
	}
	while (init->nb_rrr)
	{
		ft_reverse_rotate_a_b(stack, *init);
		init->nb_rrr--;
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
	ft_push_b(stack, init); // push b
	// ft_printf("nb_ra %d\n", init->nb_ra);
	// ft_printf("nb_rra %d\n", init->nb_rra);
	// ft_printf("nb_rb %d\n", init->nb_rb);
	// ft_printf("nb_rrb %d\n", init->nb_rrb);
}
