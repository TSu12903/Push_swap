/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:49:54 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/06 16:25:02 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	total_word(char *str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		
		j = ft_check_sign_num(str);
		if (j != 0)
		{
		 	while (str[i] == ' ' || str[i] == '+' || str[i] == '-')
				i++;
			if (str[i] >= '0' && str[i] <= '9')
				count++;
			while (str[i] >= '0' && str[i] <= '9')
				i++;
		}
		else
			return (0);
		j = 0;
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
		tmp_tab = ft_split(av[i], ' ');
		while (k-- > 0)
			tab[j++] = tmp_tab[l++];
		free(tmp_tab);
		i++;
	}
	return (tab);
}

long	*ft_parsing(char **av)
{
	int	i;
	int	j;
	int	nb_count;
	char	**tab;
	long	*tab1;

	i = 1;
	nb_count = 0;
	j = 0;
	while (av[i])
	{
		j = total_word(av[i]);
		i++;
		if (j == 0)
		{
			ft_printf("%s\n", "Error");
			return (0);
		}
		nb_count += j;
	}
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
		tab1[j] = ft_atol(tab[j]);
		j++;
	}
	ft_free(tab);
	j = 0;
	i = ft_verfi_twice(tab1, nb_count);
	if (i == 0)
	{
		free(tab1);
		return (0);
	}
	return (tab1);
}
