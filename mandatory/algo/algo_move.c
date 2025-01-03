/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:56:38 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/03 19:10:58 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_nb_max_stack_b(t_stack *stack, t_init init)
{
	init.i = 0;
	init.k = 0;
	while (init.i < stack->size_b)
	{
		if (stack->stack_b[init.i] > stack->stack_b[init.k])
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
		if (stack->stack_b[init.i] < stack->stack_b[init.k])
			init.k = init.i;
		init.i++;
	}
	return (init.k);
}

void	ft_between(t_stack *stack, t_init *init)
{
	init->j = 0;
	while (init->j < stack->size_b)
	{
		if (stack->stack_a[init->i] < stack->stack_b[init->j]
			&& stack->stack_a[init->i] > stack->stack_b[init->j + 1])
		{
			ft_printf("here1\n");
			if ((stack->size_b - init->j) < stack->size_b / 2)
				stack->count_move += stack->size_b - init->j;
			else
				stack->count_move += init->j;
		}
		else if (stack->stack_a[init->i] > stack->stack_b[init->j]
			&& init->j == stack->size_b - 1)
			{
				ft_printf("here2\n");
				stack->count_move++;
			}
		init->j++;
		ft_printf("3\n");
	}
}

void	ft_count_move(t_stack *stack, t_init *init)
{
	ft_printf("count_move start %d\n", stack->count_move);
	if (stack->stack_a[init->i] != 0)
	{
		if ((stack->size_a - init->i) < stack->size_a / 2)
			stack->count_move += stack->size_a - init->i;
		else
			stack->count_move += init->i;
	} // ra or rra
	init->k = ft_nb_max_stack_b(stack, *init);
	if (stack->stack_a[init->i] > stack->stack_b[init->k]) // rb or rrb
	{
		if ((stack->size_b - init->k) < stack->size_b / 2)
			stack->count_move += stack->size_b - init->k;
		else
			stack->count_move += init->k;
		ft_printf("1 \n");
	}
	init->j = ft_nb_min_stack_b(stack, *init);
	if (stack->stack_a[init->i] < stack->stack_b[init->j]) // rb or rrb
	{
		if ((stack->size_b - init->k) < stack->size_b / 2)
			stack->count_move += stack->size_b - init->k;
		else
			stack->count_move += init->k;
		ft_printf("2 \n");
	}
	if (stack->stack_a[init->i] > stack->stack_b[init->j]
		&& stack->stack_a[init->i] < stack->stack_b[init->k])
		ft_between(stack, init);
	stack->count_move++; // push b
	ft_printf("count_move end %d\n", stack->count_move);
}

void	ft_best_move(t_stack *stack, t_init *init)
{
	init->i = 0;
	stack->count_move = 0;
	stack->best_move = 100000000;
	init->l = 0;
	while (init->i < stack->size_a)
	{
		ft_count_move(stack, init);
//		ft_printf("count_move test%d\n", stack->count_move);
		if (stack->count_move < stack->best_move)
		{
			stack->best_move = stack->count_move;
			init->l = init->i;
			ft_printf(" retenu %d\n", init->l);
		}	
		stack->count_move = 0;
		init->i++;
	}
}