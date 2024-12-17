/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:49:54 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/17 14:29:28 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	total_word(char *str, t_init init)
{
	while (str[init.i])
	{
		init.j = ft_check_sign_num(str);
		if (init.j != 0)
		{
			init.k = 0;
			while (str[init.i] == ' ' || str[init.i] == '+'
				|| str[init.i] == '-')
				init.i++;
			if (str[init.i] >= '0' && str[init.i] <= '9')
				init.count++;
			while (str[init.i] >= '0' && str[init.i] <= '9')
				init.i++;
		}
		else
			return (0);
		init.j = 0;
	}
	return (init.count);
}

char	**ft_cut(char **tab, char **av, t_init init)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**tmp_tab;

	j = 0;
	i = 1;
	k = 0;
	while (av[i])
	{
		k = total_word(av[i], init);
		l = 0;
		tmp_tab = ft_split(av[i], ' ');
		while (k-- > 0)
			tab[j++] = tmp_tab[l++];
		free(tmp_tab);
		i++;
	}
	return (tab);
}

int	ft_parsing_verif(char **av, t_init init)
{
	int	i;
	int	j;
	int	nb_count;

	i = 0;
	nb_count = 0;
	while (av[++i])
	{
		j = total_word(av[i], init);
		if (j == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		nb_count += j;
	}
	return (nb_count);
}

long	*ft_parsing(char **av, t_init *init)
{
	int		j;
	int		nb_count;
	char	**tab;
	long	*tab1;

	nb_count = ft_parsing_verif(av, *init);
	init->nb_count_size = nb_count;
	if (nb_count == 0)
		return (0);
	tab = ft_calloc(nb_count + 1, sizeof(char *));
	if (tab == NULL)
		return (0);
	tab = ft_cut(tab, av, *init);
	tab1 = ft_calloc(nb_count + 1, sizeof(long));
	if (tab1 == NULL)
		return (0);
	j = -1;
	while (tab[++j])
		tab1[j] = ft_atol(tab[j]);
	ft_free(tab);
	j = ft_verfi_twice(tab1, nb_count);
	if (j == 0)
		return (ft_one_free(tab1));
	return (tab1);
}
