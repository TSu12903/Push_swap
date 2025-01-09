/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:30:19 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/09 13:57:49 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_init(t_init	*init)
{
	init->print = 1;
	init->i = 0;
	init->j = 1;
	init->count = 0;
}

void	ft_init_size(t_stack *stack, t_init *init)
{
	stack->size_a = init->nb_count_size;
	stack->size_b = 0;
}
