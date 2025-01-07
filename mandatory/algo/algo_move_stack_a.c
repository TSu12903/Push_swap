/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:52:13 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/07 17:36:26 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_nb_max_stack_a(t_stack *stack, t_init init)
{
	init.i = 0;
	init.k = 0;
	while (init.i < stack->size_a)
	{
		if (stack->stack_a[init.i] > stack->stack_a[init.k])
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
		if (stack->stack_a[init.i] < stack->stack_a[init.k])
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
		if (init->j -1 != -1 && stack->stack_b[init->l] < stack->stack_a[init->j]
			&& stack->stack_b[init->l] > stack->stack_a[init->j - 1])
			{
			    select_rotation_a(stack->size_a, init->j, init);
			    // ft_printf("HERE3.1 rb = %d, rrb = %d \n", init->nb_rb, init->nb_rrb);
			}
		else if (stack->stack_b[init->l] > stack->stack_a[init->j]
			&& init->j == stack->size_a)
            {
			    init->nb_rra++;
			    // ft_printf("HERE3.2 rb = %d, rrb = %d j = %d \n", init->nb_rb, init->nb_rrb, init->j);
			}
		init->j++;
	}
}

void	determine_stack_a_moves(t_stack *stack, t_init *init)
{
	init->nb_ra = 0;
	init->nb_rb = 0;
	init->nb_rra = 0;
	init->nb_rrb = 0;
    init->j = ft_nb_min_stack_a(stack, *init);
    init->k = ft_nb_max_stack_a(stack, *init);
	if (stack->stack_b[init->l] < stack->stack_a[init->j])
    { // rb or rrb
		select_rotation_a(stack->size_a, init->j, init);
        // ft_printf("HERE1 l = %d \n", stack->stack_b[init->l]);
    }
	if (stack->stack_b[init->l] > stack->stack_a[init->k])
    { // rb or rrb
		select_rotation_a(stack->size_a, init->j, init);
        // ft_printf("HERE2\n");
    }
    if (stack->stack_b[init->l] > stack->stack_a[init->j]
		&& stack->stack_b[init->l] < stack->stack_a[init->k]){
		select_moves_between_a(stack, init);
        // ft_printf("HERE3\n");
    }
}
void	ft_move_stack_a(t_stack *stack, t_init *init)
{
	init->nb_rr = 0;
	init->nb_rrr = 0;
	determine_stack_a_moves(stack, init);
	// ft_printf("nb_ra %d\n", init->nb_ra);
	// ft_printf("nb_rra %d\n", init->nb_rra);
	// ft_printf("nb_rb %d\n", init->nb_rb);
	// ft_printf("nb_rrb %d\n", init->nb_rrb);
	if (init->nb_ra != 0 && init->nb_rb != 0)
		check_reverse_rr(init);
	if (init->nb_rra != 0 && init->nb_rrb != 0)
		check_reverse_rrr(init);
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
	ft_push_a(stack, init); // push a
    // print(stack, *init);
	// ft_printf("nb_ra %d\n", init->nb_ra);
	// ft_printf("nb_rra %d\n", init->nb_rra);
	// ft_printf("nb_rb %d\n", init->nb_rb);
	// ft_printf("nb_rrb %d\n", init->nb_rrb);
}
