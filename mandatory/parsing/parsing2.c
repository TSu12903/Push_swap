/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:54:44 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/10 15:11:43 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_verfi_twice(long *str, int num)
{
	int	j;
	int	i;

	i = 0;
	if (str[i] > 2147483647 || str[i] < -2147483648)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (i < num)
	{
		j = 0;
		while (j < i)
		{
			if (str[i] > 2147483647 || str[i] < -2147483648 || str[i] == str[j])
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_check_sign_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' '
				|| str[i] == '+' || str[i] == '-'))
			return (0);
		if ((str[i] == '+' || str[i] == '-')
			&& (!(str[i + 1] >= '0' && str[i + 1] <= '9')
				|| (str[i + 1] == ' ')))
			return (0);
		if ((str[i] >= '0' && str[i] <= '9')
			&& !(str[i + 1] == ' ' || str[i + 1] == '\0'
				|| (str[i + 1] >= '0' && str[i + 1] <= '9')))
			return (0);
		i++;
	}
	return (i);
}
