/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:56:38 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/19 16:24:56 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_nb_max_stack_b(t_stack *stack, t_init init)
{
	init.i= 0;
	init.k= 0;
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
	init.i= 0;
	init.k= 0;
	while (init.i < stack->size_b)
	{
		if (stack->stack_b[init.i] < stack->stack_b[init.k])
			init.k = init.i;
		init.i++;
	}
	
	return (init.k);
}
void	ft_Between(t_stack *stack, t_init *init)
{
	init->j = 0;
	while (init->j < stack->size_b)
	{
		if (stack->stack_a[init->i] > stack->stack_b[init->j] && stack->stack_a[init->i] < stack->stack_b[init->j + 1])
		{
			if (( stack->size_b - init->j) < stack->size_b / 2)
				stack->count_move +=  stack->size_b - init->j - 1;
			else
				stack->count_move += init->j - 1;
		}
		else if (stack->stack_a[init->i] > stack->stack_b[init->j] && stack->stack_b[init->j + 1])
			stack->count_move++;
		init->j++;
	}
}

void   ft_count_move(t_stack *stack, t_init *init)
{
	if (stack->stack_a[init->i] != 0)
		stack->count_move += init->i; // ra or rra
	init->k = ft_nb_max_stack_b(stack, *init);
	if (stack->stack_a[init->i] > stack->stack_b[init->k]) // rb or rrb
	{
		if ((stack->size_b - init->k) < stack->size_b / 2)
			stack->count_move += stack->size_b - init->k - 1;
		else
			stack->count_move += init->k -1;
		ft_printf("1");
	}
	init->j = ft_nb_min_stack_b(stack, *init);
	if (stack->stack_a[init->i] < stack->stack_b[init->j]) // rb or rrb
	{
		if ((stack->size_b - init->k) < stack->size_b / 2)
			stack->count_move += stack->size_b - init->k - 1;
		else
			stack->count_move += init->k - 1;
		ft_printf("2");
	}
	if (stack->stack_a[init->i] > stack->stack_b[init->j] && stack->stack_a[init->i] < stack->stack_b[init->k])
		ft_Between(stack, init);
	stack->count_move++; // push b
}

void	ft_best_move(t_stack *stack, t_init *init)
{
	init->i = 0;
	stack->count_move = 0;
	stack->best_move = 100000000;
	init->l = 0;
	while(init->i < stack->size_a - 3)
	{

		ft_count_move(stack, init);
		ft_printf("count_move %d\n", stack->count_move);
		if (stack->count_move < stack->best_move)
		{
			stack->best_move = stack->count_move;
			init->l = init->i;
		}	
		stack->count_move = 0;
		init->i++;
	}
}