/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:55:53 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/12 13:26:44 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	long	*stack_a;
	long	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	stack_a = ft_parsing(av);
	stack_a = ft_swap_a(stack_a);
	///
	i = 0;
	if (stack_a != 0)
	{
		while (stack_a[i])
		{
			ft_printf("%d\n", stack_a[i]);
			i++;
		}
		free(stack_a);
	}
	////
	return (0);
}
