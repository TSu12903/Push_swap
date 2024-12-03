/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:49:54 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/03 15:39:43 by tcybak           ###   ########.fr       */
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

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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
			if (!tmp_tab)
            		{
               			ft_free_tab(tab);
               			free(tmp_tab);
                		return NULL;
           		}
		}
		else
		{
			tmp_tab = ft_calloc(k + 1, sizeof(char*));
			if (!tmp_tab)
            		{
               			ft_free_tab(tab);
               			free(tmp_tab);
                		return NULL;
           		}	
			tmp_tab[0] = av[i];
		}
		while (k > 0)
		{
			tab[j] = tmp_tab[l];
			j++;
			l++;
			k--;
		}
		free(tmp_tab);
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
//	int	*tab1;

	i = 1;
	if (ac == 1)
		return (0);
	nb_count = 0;
	while (av[i])
	{
		nb_count += total_word(av[i]);
		i++;
	}
	tab = ft_calloc(nb_count + 1, sizeof(char*));
	if (tab == NULL)
		return (0);

	tab = ft_cut(tab, av);
	j = 0;
	while (tab[j])
	{
		ft_printf("%s\n", tab[j]);
		j++;
	}
	ft_free_tab(tab);
	return (0);
}
