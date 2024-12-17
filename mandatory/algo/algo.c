/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:11:04 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/17 14:50:30 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_classify(t_stack *stack, t_init *init)
{
	init->i = 0;
	init->j = 0;
	while (init->j < init->nb_count_size)
	{
		if (stack->stack_a[init->i] < stack->stack_a[init->j])
			return (0);
		init->j++;
	}
	return (1);
}

void	ft_start(t_stack *stack, t_init *init)
{
	if (ft_classify(stack, init) == 0)
		return ;		
	ft_push_b(stack, init);
	ft_push_b(stack, init);
}

void    ft_algo(t_stack *stack, t_init *init)
{
	ft_start(stack, init);
}