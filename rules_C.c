/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_C.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:29:51 by bifernan          #+#    #+#             */
/*   Updated: 2024/02/26 14:35:45 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_dlist *stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_dlist *stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}

void	ft_pb(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	ft_ra(t_dlist *stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}
