/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:55:53 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/10 15:10:12 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_init	*init;

	if (ac == 1)
		return (0);
	init = malloc(sizeof(t_init));
	if (init == NULL)
		return (0);
	stack = malloc(sizeof(t_stack));
	if (stack == 0)
		return (ft_free_all(stack, init));
	ft_init(init);
	stack->stack_a = ft_parsing(av, init);
	if (stack->stack_a)
	{
		stack->stack_b = ft_calloc(init->nb_count_size, sizeof(long));
		if (stack->stack_b == NULL)
			return (0);
	}
	else
		return (ft_free_all(stack, init));
	ft_init_size(stack, init);
	ft_algo(stack, init);
	ft_free_all(stack, init);
	return (0);
}
