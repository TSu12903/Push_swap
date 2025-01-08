/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:11:04 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/08 14:26:33 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_classify_a(t_stack *stack, t_init *init)
{
	init->i = 0;
	init->j = 1;
	while (init->j < init->nb_count_size)
	{
		if (stack->stack_a[init->i] > stack->stack_a[init->j])
			return (0);
		init->j++;
		init->i++;
	}
	return (1);
}

// int	ft_classify_b(t_stack *stack, t_init *init)
// {
// 	init->i = 0;
// 	init->j = 0;
// 	while (init->j < init->nb_count_size)
// 	{
// 		if (stack->stack_b[init->i] < stack->stack_b[init->j])
// 			return (0);
// 		init->j++;
// 	}
// 	return (1);
// }

void	ft_start(t_stack *stack, t_init *init)
{
	if (ft_classify_a(stack, init) != 0)
		return ;
	ft_push_b(stack, init);
	ft_push_b(stack, init);
	// if (ft_classify_b(stack, init) == 0)
	// 	ft_swap_b(stack, init);
}

void	ft_algo(t_stack *stack, t_init *init)
{
	if (stack->size_a == 2)
	{
		if (ft_classify_a(stack, init) == 0)
			ft_swap_a(stack, init);
	}
	if (stack->size_a <= 3)
	{
		ft_less_tree(stack, init);
		return ;
	}
	ft_start(stack, init);
	while (stack->size_a > 3)
	{
		ft_best_move(stack, init);
		ft_move_stack_b(stack, init);
		// print(stack , *init);
	}
	ft_less_tree(stack, init);
	init->l = 0;
	while (stack->size_b > 0)
	{
		ft_move_stack_a(stack, init);
		// print(stack , *init);
	}
	init->min = ft_nb_min_stack_a(stack, *init);
	if (init->min != 0)
	{
		select_rotation_a(stack->size_a, init->min, init);
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
	}
}
