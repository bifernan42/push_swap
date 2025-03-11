/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_B.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:17:17 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:41:06 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_dlist *stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}

void	ft_rra(t_dlist *stack_a)
{
	ft_rrotate(stack_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_dlist *stack_b)
{
	ft_rrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
	write(1, "rrr\n", 4);
}
