/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:58:24 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/12 15:58:55 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

////////////////////////////////////////
///				Utils.c				///
//////////////////////////////////////

void	ft_free(char **str);
long	*ft_one_free(long *tab1);
int		ft_strlen_long(long	*tab);

////////////////////////////////////////
///				Parsing2.c			///
//////////////////////////////////////

int		ft_verfi_twice(long *str, int num);

////////////////////////////////////////
///				Main.c				///
//////////////////////////////////////

long	*ft_parsing(char **av);

////////////////////////////////////////
///				Order.c				///
//////////////////////////////////////

void    ft_swap_a(long *tab, int i);
void    ft_swap_b(long *tab, int i);
void    ft_swap_ss(long *tab_a, long *tab_b);


#endif
