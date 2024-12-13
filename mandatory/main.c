/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:55:53 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/13 10:42:52 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;
	t_init	*init;

	stack = malloc(sizeof(t_stack));
	init = malloc(sizeof(t_init));
	init->i = 1;
	if (ac == 1)
		return (0);
	stack->stack_a = ft_parsing(av);
	ft_swap_a(stack, init);
	///
	init->i = 0;
	if (stack->stack_a != 0)
	{
		while (stack->stack_a[init->i])
		{
			ft_printf("%d\n", stack->stack_a[init->i]);
			init->i++;
		}
		free(stack->stack_a);
	}
	////
	return (0);
}
