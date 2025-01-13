/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:21:11 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/10 15:57:22 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	select_rotation_a(int stack, int far, t_init *init)
{
	if ((stack - far) <= stack / 2)
		init->nb_rra += stack - far;
	else
		init->nb_ra += far;
}

void	select_rotation_b(int stack, int far, t_init *init)
{
	if ((stack - far) <= stack / 2)
		init->nb_rrb += stack - far;
	else
		init->nb_rb += far;
}

void	check_reverse_rr(t_init *init)
{
	if (init->nb_ra > init->nb_rb)
	{
		init->nb_rr = init->nb_rb;
		init->nb_ra = init->nb_ra - init->nb_rb;
		init->nb_rb = 0;
	}
	else if (init->nb_ra < init->nb_rb)
	{
		init->nb_rr = init->nb_ra;
		init->nb_rb = init->nb_rb - init->nb_ra;
		init->nb_ra = 0;
	}
	else
	{
		init->nb_rr += init->nb_ra;
		init->nb_ra = 0;
		init->nb_rb = 0;
	}
}

void	check_reverse_rrr(t_init *init)
{
	if (init->nb_rra > init->nb_rrb)
	{
		init->nb_rrr = init->nb_rrb;
		init->nb_rra = init->nb_rra - init->nb_rrb;
		init->nb_rrb = 0;
	}
	else if (init->nb_rra < init->nb_rrb)
	{
		init->nb_rrr = init->nb_rra;
		init->nb_rrb = init->nb_rrb - init->nb_rra;
		init->nb_rra = 0;
	}
	else
	{
		init->nb_rrr += init->nb_rra;
		init->nb_rra = 0;
		init->nb_rrb = 0;
	}
}
