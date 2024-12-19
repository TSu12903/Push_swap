/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:07:48 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/19 18:21:18 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate_a_b(t_stack *stack, t_init init)
{
	init.print = 0;
	ft_reverse_rotate_a(stack, init);
	ft_reverse_rotate_b(stack, init);
	write(2, "rrr\n", 4);
}
