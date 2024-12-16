/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_s_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:02 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/16 18:11:37 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_stack *stack, t_init *init)
{
	long	swap;

	if (stack->size_a <= 1)
		return ;
	else
	{
		swap = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = swap;
		if (init->print != 0)
			ft_printf("sa\n");
	}
}

void	ft_swap_b(t_stack *stack, t_init *init)
{
	long	swap;

	if (stack->size_b < 1)
		return ;
	else
	{
		swap = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = swap;
		if (init->print != 0)
			ft_printf("sa\n");
	}
}

void	ft_swap_ss(t_stack *stack)
{
	ft_swap_a(stack, 0);
	ft_swap_b(stack, 0);
	ft_printf("ss\n");
}

void	ft_push_b(t_stack *stack, t_init *init)
{
	init->i = 0;
	init->j = 1;
	stack->size_b += 1;
	stack->size_a -= 1;
	if (stack->stack_a == 0)
		return ;
	while (init->j < stack->size_b)
	{
		init->k = stack->stack_b[init->i];
		stack->stack_b[init->i] = stack->stack_b[init->j];
		stack->stack_b[init->j] = init->k;
		init->j++;
	}
	stack->stack_b[0] = stack->stack_a[0];
	init->i = 0;
	init->j = 1;
	while (init->j <= stack->size_a)
	{
		stack->stack_a[init->i] = stack->stack_a[init->j];
		init->j++;
		init->i++;
	}
	stack->stack_a[stack->size_a] = '\0';
	ft_printf("pb\n");
}

void	ft_push_a(t_stack *stack, t_init *init)
{
	init->i = 0;
	init->j = 1;
	stack->size_b -= 1;
	stack->size_a += 1;
	if (stack->stack_b == 0)
		return ;
	while (init->j < stack->size_a)
	{
		init->k = stack->stack_a[init->i];
		stack->stack_a[init->i] = stack->stack_a[init->j];
		stack->stack_a[init->j] = init->k;
		init->j++;
	}
	stack->stack_a[0] = stack->stack_b[0];
	init->i = 0;
	init->j = 1;
	while (init->j <= stack->size_b)
	{
		stack->stack_b[init->i] = stack->stack_b[init->j];
		init->j++;
		init->i++;
	}
	stack->stack_a[stack->size_a] = '\0';
	ft_printf("pa\n");
}
