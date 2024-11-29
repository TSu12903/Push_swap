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

static int	ft_check_sign_num(char *str)
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
			&& !(str[i + 1] == ' ' || str[i + 1] == '\0'))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	int		str;
	int		j;
	char	**tab;

	if (ac == 1)
		return (0);
	i = 1;
	while (av[i])
	{
		str = ft_check_sign_num(av[i]);
		if (str == 0)
		{
			ft_printf("%s", "Error");
			return (0);
		}
		i++;
	}
	i = 1;
	while (av[i])
	{
		tab = ft_split(av[i], ' ');
		j = 0;
		while(tab[j])
		{
			ft_printf("%s\n", tab[j]);
			free(tab[j]);
			j++;
		}
		free(tab);
		i++;
	}
}
