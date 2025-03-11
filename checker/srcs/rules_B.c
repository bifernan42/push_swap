/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_B.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:17:17 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 14:04:44 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rb(t_dlist *stack_b)
{
	ft_rotate(stack_b);
}

void	ft_rr(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_rra(t_dlist *stack_a)
{
	ft_rrotate(stack_a);
}

void	ft_rrb(t_dlist *stack_b)
{
	ft_rrotate(stack_b);
}

void	ft_rrr(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
}
