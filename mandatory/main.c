/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:55:53 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/09 13:17:15 by tcybak           ###   ########.fr       */
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
	if (init == 0)
		return (0);
	stack = malloc(sizeof(t_stack));
	if (stack == 0)
		return (0);
	ft_init(init);
	stack->stack_a = ft_parsing(av, init);
	if (stack->stack_a)
		stack->stack_b = ft_calloc(init->nb_count_size, sizeof(long));
	else
		return (0);
	ft_init_size(stack, init);
	ft_algo(stack, init);
	if (stack->stack_a)
		free(stack->stack_b);
	free(stack->stack_a);
	free(stack);
	free(init);
	return (0);
}
