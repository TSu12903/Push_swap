/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:21:11 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/06 12:27:19 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	calculate_moves_b(t_stack *stack, t_init *init)
{
		if ((stack->size_b - init->k) < stack->size_b / 2)
			stack->count_move += stack->size_b - init->k;
		else
			stack->count_move += init->k;
}

void	calculate_moves_a(t_stack *stack, t_init *init)
{
		if ((stack->size_a - init->i) < stack->size_a / 2)
			stack->count_move += stack->size_a - init->i;
		else
			stack->count_move += init->i;
}

void	select_rotation_b(t_stack *stack, t_init *init)
{
		if ((stack->size_b - init->k) < stack->size_b / 2)
			init->nb_rb += stack->size_b - init->k;
		else
			init->nb_rrb += init->k;
}
void	select_rotation_a(t_stack *stack, t_init *init)
{
		if ((stack->size_a - init->l) < stack->size_a / 2)
			init->nb_ra += stack->size_a - init->l;
		else
			init->nb_rra += init->l;
}
/*	select_rotation_a(stack->size_a, init->l);
void	select_rotation_a(int *stack, int tmp)
{
	
}*/