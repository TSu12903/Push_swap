/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:47:30 by tsugeku           #+#    #+#             */
/*   Updated: 2024/12/18 19:27:44 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_a(t_stack *stack, t_init init)
{
	init.k = stack->stack_a[0];
	init.i = 1;
	init.j = 0;
	while (init.i <= stack->size_a - 1)
	{
		stack->stack_a[init.j] = stack->stack_a[init.i];
		init.i++;
		init.j++;
	}
	stack->stack_a[stack->size_a - 1] = init.k;
	if (init.print != NO_PRINT)
			write(2, "ra\n", 3);
}

void	ft_rotate_b(t_stack *stack, t_init init)
{
	init.k = stack->stack_b[0];
	init.i = 1;
	init.j = 0;
	while (init.i <= stack->size_b - 1)
	{
		stack->stack_b[init.j] = stack->stack_b[init.i];
		init.i++;
		init.j++;
	}
	stack->stack_b[stack->size_b - 1] = init.k;
	if (init.print != 0)
			write(2, "rb\n", 3);
}

void	ft_rotate_a_b(t_stack *stack, t_init init)
{
	init.print = 0;
	ft_rotate_a(stack, init);
	ft_rotate_b(stack, init);
	write(2,"rr\n", 3);
}
void	ft_reverse_rotate_a(t_stack *stack, t_init init)
{
	init.i = 0;
	init.j = 1;
	if (stack->stack_a == 0)
		return ;
	init.l = stack->stack_a[stack->size_a - 1];
	while (init.j < stack->size_a)
	{
		init.k = stack->stack_a[init.i];
		stack->stack_a[init.i] = stack->stack_a[init.j];
		stack->stack_a[init.j] = init.k;
		init.j++;
	}
	stack->stack_a[0] = init.l;
	if (init.print != 0)
			write(2, "rra\n", 4);
}
void	ft_reverse_rotate_b(t_stack *stack, t_init init)
{
	init.i = 0;
	init.j = 1;
	if (stack->stack_b == 0)
		return ;
	init.l = stack->stack_b[stack->size_b - 1];
	while (init.j < stack->size_b)
	{
		init.k = stack->stack_b[init.i];
		stack->stack_b[init.i] = stack->stack_b[init.j];
		stack->stack_b[init.j] = init.k;
		init.j++;
	}
	stack->stack_b[0] = init.l;
	if (init.print != 0)
			write(2,"rrb\n",4);
}