/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:49:54 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/04 15:03:53 by tcybak           ###   ########.fr       */
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
		{
			ft_printf("%s", "Error");
			return (0);
		}
		if ((str[i] == '+' || str[i] == '-')
			&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
		{
			ft_printf("%s", "Error");
			return (0);
		}
		if ((str[i] >= '0' && str[i] <= '9')
			&& !(str[i + 1] == ' ' || str[i + 1] == '\0'
				|| (str[i] >= '0' && str[i] <= '9')))
		{
			ft_printf("%s", "Error");
			return (0);
		}
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
			{
				ft_printf("%s", "Error");
				return (0);
			}
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

char	**ft_cut(char **tab, char **av)
{
	int	i;
	int	j;
	int	k;
	int	l;
	char	**tmp_tab;

	j = 0;
	i = 1;
	k = 0;
	while (av[i])
	{
		k = total_word(av[i]);
		l = 0;
		if (k > 1)
		{
			tmp_tab = ft_split(av[i], ' ');
			while (k-- > 0)
				tab[j++] = tmp_tab[l++];
			free(tmp_tab);
		}
		else
			tab[j++] = av[i];
		i++;
	}
	return (tab);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	nb_count;
	char	**tab;
	int	*tab1;

	i = 1;
	if (ac == 1)
		return (0);
	nb_count = 0;
	while (av[i])
	{
		nb_count += total_word(av[i]);
		j = ft_check_sign_num(av[i]);
		i++;
	}
	if (j == 0 || nb_count == 0)
		return (0);
	tab = ft_calloc(nb_count + 1, sizeof(char*));
	if (tab == NULL)
		return (0);
	tab = ft_cut(tab, av);
	j = 0;
	tab1 = ft_calloc(nb_count + 1, sizeof(long));
	if (tab1 == NULL)
		return (0);
	while (tab[j])
	{
		tab1[j] = ft_atoi(tab[j]);
		free(tab[j]);
		j++;
	}
	i = 0;
	j = 0;
	i = ft_verfi_twice(tab1, nb_count);
	if (i != 0)
	{
		while (j < nb_count)
		{
			printf("%d\n", tab1[j]);
			j++;
		}
	}
		
	free(tab1);
	free(tab);
	return (0);
}
