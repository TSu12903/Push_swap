/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_s_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:02 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/13 10:44:53 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void   ft_swap_a(t_stack *stack, t_init *init)
{  
    long    swap;

    stack->size_a = ft_strlen_long(stack->stack_a);
    if (stack->size_a <= 1)
        return ;
    else
    {
        swap = stack->stack_a[0];
        stack->stack_a[0] = stack->stack_a[1];
        stack->stack_a[1] = swap;
        if (init->i != 0)
            ft_printf("sa\n");
    }
}
void   ft_swap_b(t_stack *stack, t_init *init)
{  
    long    swap;

    stack->size_b = ft_strlen_long(stack->stack_b);
    if (stack->size_b < 1)
        return ;
    else
    {
        swap = stack->stack_b[0];
        stack->stack_b[0] = stack->stack_b[1];
        stack->stack_b[1] = swap;
        if (init->i != 0)
            ft_printf("sa\n");
    }
}
void    ft_swap_ss(t_stack *stack,t_init *init)
{
    init->i = 0;
    ft_swap_a(stack, init);
    ft_swap_b(stack, init);
    ft_printf("ss\n");
}
