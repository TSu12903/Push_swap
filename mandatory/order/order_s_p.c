/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_s_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:02 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/13 10:07:33 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void   ft_swap_a(long *tab, int i)
{
    long swap;
    int size;

    size = ft_strlen_long(tab);
    if (size < 1)
        return ;
    else
    {
        swap = tab[0];
        tab[0] = tab[1];
        tab[1] = swap;
        if (i != 0)
            ft_printf("sa\n");
    }
}
void    ft_swap_b(long *tab, int i)
{
    long swap;
    int size;

    size = ft_strlen_long(tab);
    if (size < 1)
        return ;
    else
    {
        swap = tab[0];
        tab[0] = tab[1];
        tab[1] = swap; 
        if (i != 0)
            ft_printf("sa\n");
    }
}
void    ft_swap_ss(long *tab_a, long *tab_b)
{
    int i;

    i = 0;
    ft_swap_a(tab_a, i);
    ft_swap_b(tab_b, i);
    ft_printf("ss\n");
}
void    ft_push_a(long *tab_a, long *tab_b)
{
    int size;

    size = ft_strlen_long(tab_b);
    if (size < 1)
        return ;
    
}