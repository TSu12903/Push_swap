/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:01:22 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/16 14:28:16 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

long	*ft_one_free(long *tab1)
{
	free(tab1);
	return (0);
}
int	ft_strlen_long(long	*tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return(i);
}

// int	ft_compare(t_stack *stack)
// {
// 	while
// }