/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:55:53 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/18 13:18:10 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	t_stack	*stack;
	t_init	*init;
	
	init = malloc(sizeof(t_init));
	if (init == 0)
		return (0);
	stack = malloc(sizeof(t_stack));
	if (stack == 0)
		return (0);
	ft_init(init);
	stack->stack_a = ft_parsing(av, init);
	if (stack->stack_a)
		stack->stack_b = ft_calloc(init->nb_count_size, sizeof(long));
	stack->size_a = init->nb_count_size;
	stack->size_b = 0;
	ft_algo(stack, init);
	init->i = 0;
	if (stack->stack_a)
	{
		while (init->i < stack->size_a)
		{
			ft_printf("stack_a--%d\n", stack->stack_a[init->i]);
			init->i++;
		}
		free(stack->stack_a);
	}
	init->i = 0;
	if (stack->size_b)
	{
		while (init->i < stack->size_b)
		{
			ft_printf("stack_b++%d\n", stack->stack_b[init->i]);
			init->i++;
		}
	}
	if (stack->stack_a)
		free(stack->stack_b);
	free(stack);
	free(init);
	return (0);
}
