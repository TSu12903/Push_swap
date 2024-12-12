/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:54:02 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/12 13:38:29 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long    *ft_swap_a(long *tab)
{
    long swap;
    int size;

    size = ft_strlen_long(tab);
    if (size < 1)
        return (tab);
    else
    {
        swap = tab[0];
        tab[0] = tab[1];
        tab[1] = swap;  
    }
    return (tab);
}
long    *ft_swap_b(long *tab)
{
    long swap;
    int size;

    size = ft_strlen_long(tab);
    if (size < 1)
        return (tab);
    else
    {
        swap = tab[0];
        tab[0] = tab[1];
        tab[1] = swap;  
    }
    return (tab);
}
