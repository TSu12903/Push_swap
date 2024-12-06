/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:55:53 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/06 17:04:31 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	long	*tab1;
	int		i;

	if (ac == 1)
		return (0);
	tab1 = ft_parsing(av);
	i = 0;
	if (tab1 != 0)
	{
		while (tab1[i])
		{
			ft_printf("%d\n", tab1[i]);
			i++;
		}
		free(tab1);
	}
	return (0);
}
