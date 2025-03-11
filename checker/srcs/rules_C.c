/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_C.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:29:51 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 14:05:10 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_dlist *stack_a)
{
	ft_swap(stack_a);
}

void	ft_sb(t_dlist *stack_b)
{
	ft_swap(stack_b);
}

void	ft_ss(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	ft_pb(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_push(stack_a, stack_b);
}

void	ft_ra(t_dlist *stack_a)
{
	ft_rotate(stack_a);
}
