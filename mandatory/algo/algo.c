/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:11:04 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/16 15:24:40 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_start(t_stack *stack, t_init *init)
{
	ft_push_b(stack, init);
	ft_push_b(stack, init);
}

void    ft_algo(t_stack *stack, t_init *init)
{
	ft_start(stack, init);
}