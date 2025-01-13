/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:01:22 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/13 11:25:02 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

long	*ft_one_free(long *tab1)
{
	free(tab1);
	return (0);
}

int	ft_free_all(t_stack *stack, t_init *init)
{
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->stack_b)
		free(stack->stack_b);
	if (stack)
		free(stack);
	if (init)
		free(init);
	return (0);
}

int	ft_free_all_except_b(t_stack *stack, t_init *init)
{
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack)
		free(stack);
	if (init)
		free(init);
	return (0);
}

int	ft_free_init(t_init *init)
{
	if (init)
		free(init);
	return (0);
}
