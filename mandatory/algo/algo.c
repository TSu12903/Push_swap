/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:11:04 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/09 13:45:28 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_classify_a(t_stack *stack, t_init *init)
{
	init->i = 0;
	init->j = 1;
	while (init->j < stack->size_a)
	{
		if (stack->stack_a[init->i] > stack->stack_a[init->j])
			return (0);
		init->j++;
		init->i++;
	}
	return (1);
}

void	execute_rotation_a(t_stack *stack, t_init *init)
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

void	ft_start(t_stack *stack, t_init *init)
{
	if (ft_classify_a(stack, init) != 0)
		return ;
	ft_push_b(stack, init);
	ft_push_b(stack, init);
}

void	ft_algo(t_stack *stack, t_init *init)
{
	if (ft_classify_a(stack, init) != 0)
		return ;
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
	}
	ft_less_tree(stack, init);
	init->l = 0;
	while (stack->size_b > 0)
		ft_move_stack_a(stack, init);
	init->min = ft_nb_min_stack_a(stack, *init);
	if (init->min != 0)
		execute_rotation_a(stack, init);
}
