/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsugeku <tsugeku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:47:30 by tsugeku           #+#    #+#             */
/*   Updated: 2024/12/15 01:16:54 by tsugeku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_a(t_stack *stack, t_init *init)
{
	init->k = stack->stack_a[0];
	init->i = 1;
	init->j = 0;
	stack->size_a = ft_strlen_long(stack->stack_a);
	while (init->i <= stack->size_a - 1)
	{
		stack->stack_a[init->j] = stack->stack_a[init->i];
		init->i++;
		init->j++;
	}
	stack->stack_a[stack->size_a - 1] = init->k;
}

void	ft_rotate_b(t_stack *stack, t_init *init)
{
	init->k = stack->stack_b[0];
	init->i = 1;
	init->j = 0;
	stack->size_b = ft_strlen_long(stack->stack_b);
	while (init->i <= stack->size_b - 1)
	{
		stack->stack_b[init->j] = stack->stack_b[init->i];
		init->i++;
		init->j++;
	}
	stack->stack_b[stack->size_b - 1] = init->k;
}