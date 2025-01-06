/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:01:22 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/06 10:49:48 by tcybak           ###   ########.fr       */
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

void	calculate_moves_b(t_stack *stack, t_init *init)
{
		if ((stack->size_b - init->k) < stack->size_b / 2)
			stack->count_move += stack->size_b - init->k;
		else
			stack->count_move += init->k;
}