/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:21:11 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/06 16:46:58 by tcybak           ###   ########.fr       */
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

void	select_rotation_a(int stack, int far, t_init *init)
{
		if ((stack - far) < stack / 2)
			init->nb_rra += stack - far;
		else
			init->nb_ra += far;
}

void	select_rotation_b(int stack, int far, t_init *init)
{
		if ((stack - far) < stack / 2)
			init->nb_rrb += stack - far;
		else
			init->nb_rb += far;
		ft_printf("stack = %d position = %d \n",stack, far);
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
