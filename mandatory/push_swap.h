/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsugeku <tsugeku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:58:24 by tcybak            #+#    #+#             */
/*   Updated: 2024/12/15 01:13:15 by tsugeku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	long	*stack_a;
	long	*stack_b;
	int		size_a;
	int		size_b;
}			t_stack;

typedef struct s_init
{
	int	i;
	int	j;
	int	k;
}		t_init;

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
///				Order_s_p.c				///
//////////////////////////////////////

void	ft_swap_a(t_stack *stack, t_init *init);
void	ft_swap_b(t_stack *stack, t_init *init);
void	ft_swap_ss(t_stack *stack, t_init *init);
void	ft_push_b(t_stack *stack, t_init *init);
void	ft_push_a(t_stack *stack, t_init *init);

////////////////////////////////////////
///				Order_r.c				///
//////////////////////////////////////

void	ft_rotate_a(t_stack *stack, t_init *init);
void    ft_rotate_b(t_stack *stack, t_init *init);

#endif
