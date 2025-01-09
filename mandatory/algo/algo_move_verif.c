/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move_verif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:56:38 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/09 13:44:34 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_nb_max_stack_b(t_stack *stack, t_init init)
{
	init.i = 0;
	init.k = 0;
	while (init.i < stack->size_b)
	{
		if (stack->stack_b[init.i] >= stack->stack_b[init.k])
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
		if (stack->stack_b[init.i] <= stack->stack_b[init.k])
			init.k = init.i;
		init.i++;
	}
	return (init.k);
}

void	calcul_moves_between_b(t_stack *stack, t_init *init)
{
	init->j = 0;
	while (init->j < stack->size_b)
	{
		if (init->j -1 != -1
			&& (stack->stack_a[init->i] > stack->stack_b[init->j]
				&& stack->stack_a[init->i] < stack->stack_b[init->j - 1]))
			select_rotation_b(stack->size_b, init->j, init);
		else if (stack->stack_a[init->i] > stack->stack_b[init->j]
			&& init->j == stack->size_b
			&& stack->stack_a[init->i] < stack->stack_b[0])
			init->nb_rrb++;
		init->j++;
	}
}

int	calculate_total_moves(t_stack *stack, t_init *init)
{
	init->nb_ra = 0;
	init->nb_rb = 0;
	init->nb_rra = 0;
	init->nb_rrb = 0;
	init->nb_rr = 0;
	init->nb_rrr = 0;
	if (init->i != 0)
		select_rotation_a(stack->size_a, init->i, init);
	init->max = ft_nb_max_stack_b(stack, *init);
	if (stack->stack_a[init->i] > stack->stack_b[init->max])
		select_rotation_b(stack->size_b, init->max, init);
	init->min = ft_nb_min_stack_b(stack, *init);
	if (stack->stack_a[init->i] < stack->stack_b[init->min])
		select_rotation_b(stack->size_b, init->max, init);
	if (stack->stack_a[init->i] > stack->stack_b[init->min]
		&& stack->stack_a[init->i] < stack->stack_b[init->max])
		calcul_moves_between_b(stack, init);
	if (init->nb_ra != 0 && init->nb_rb != 0)
		check_reverse_rr(init);
	if (init->nb_rra != 0 && init->nb_rrb != 0)
		check_reverse_rrr(init);
	stack->count_move = init->nb_ra + init->nb_rb
		+ init->nb_rra + init->nb_rrb + init->nb_rrr + init->nb_rr + 1;
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
		if (stack->best_move <= 0)
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
