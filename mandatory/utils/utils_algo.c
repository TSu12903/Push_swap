/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:21:11 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/06 14:17:56 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	calculate_moves(int stack1, int far , t_stack *stack)
{
		if ((stack1 - far) < stack1 / 2)
			stack->count_move += stack1 - far;
		else
			stack->count_move += far;
}

void	select_rotation(int stack, int far, t_init *init)
{
		if ((stack - far) < stack / 2)
			init->nb_rb += stack - far;
		else
			init->nb_rrb += far;
}
int	check_reverse(int ra, int rb, int rr)
{
	if  (ra > rb)
	{
		rr = rb;
		rb = 0;
	 ra = ra - rb;
	}
	else if  (ra < rb)
	{
		rr = ra;
	 ra = 0;
		rb = rb - ra;
	}
	else
		rr += ra;
	return (rr);
}
