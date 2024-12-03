/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:49:54 by tcybak            #+#    #+#             */
/*   Updated: 2024/11/27 16:49:56 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
			&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
		if ((str[i] >= '0' && str[i] <= '9')
			&& !(str[i + 1] == ' ' || str[i + 1] == '\0'
				|| (str[i] >= '0' && str[i] <= '9')))
			return (0);
		i++;
	}
	return (i);
}

int	ft_verfi_twice(int *str, int num)
{
	int	j;
	int	i;

	i = 0;
	while (i < num)
	{
		j = 1;
		while (j < i)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	total_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '+' || str[i] == '-') 
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++; 
		count++;
	}
	return (count);
}

int	main(int ac, char **av)
{
	int		i;
	int		*str;
	int		j;
	char		**tab;
	int		nb_count;
	int		k;

	if (ac == 1)
		return (0);
	i = 1;
	j = 0;
	while (av[i])
	{
		j = ft_check_sign_num(av[i]);
		
		if (j == 0)
		{
			ft_printf("%s", "Error");
			return (0);
		}
		i++;
	}
	i = 1;
	nb_count = 0;
	while (av[i])
	{
		nb_count += total_word(av[i]);
		i++;
	}
	str = calloc(nb_count, sizeof(long));
	if (str == 0)
		return (0);
	i = 1;
	k = 0;
	while (av[i])
	{
		tab = ft_split(av[i], ' ');
		i++;
	}
	j = 0;
	while (tab[j])
	{
		str[k] = ft_atoi(tab[j]);
		free(tab[j]);
		k++;
		j++;
	}
	free(tab);
	j = ft_verfi_twice(str, nb_count);
	if (j == 0)
	{
		ft_printf("%s", "Error");
		free(str);
		return (0);
	}
	j = 0;
	while (j <= nb_count - 1)
	{
		ft_printf("%d\n", str[j]);
		j++;
	}
	free(str);
}
