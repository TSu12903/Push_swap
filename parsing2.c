/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:54:44 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/06 17:12:17 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verfi_twice(long *str, int num)
{
	int	j;
	int	i;

	i = 0;
	if (str[i] > 2147483647 || str[i] < -2147483648)
	{
		ft_printf("%s\n", "Error");
		return (0);
	}
	while (i < num)
	{
		j = 0;
		while (j < i)
		{
			if (str[i] > 2147483647 || str[i] < -2147483648 || str[i] == str[j])
			{
				ft_printf("%s\n", "Error");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (i);
}
