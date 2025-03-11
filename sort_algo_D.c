/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_D.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:42:26 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:58:53 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getmedian(t_dlist *stack)
{
	int		stack_len;
	int		applicant;
	int		smaller_numbers;
	t_node	*temp1;
	t_node	*temp2;

	stack_len = stack->dlst_len;
	temp1 = stack->p_head;
	while (temp1 != NULL)
	{
		smaller_numbers = 0;
		applicant = temp1->data;
		temp2 = stack->p_head;
		while (temp2 != NULL)
		{
			if (temp2->data < applicant)
				smaller_numbers++;
			temp2 = temp2->p_next;
		}
		if (smaller_numbers == (stack_len / 2))
			return (applicant);
		temp1 = temp1->p_next;
	}
	return (0);
}

void	ft_empty_b(t_dlist *a, t_dlist *b)
{
	t_node	*cheapest;

	if (!b->dlst_len)
		return ;
	ft_set_target_node(a, b);
	ft_set_cost(a, b);
	cheapest = ft_get_cheapest(b);
	ft_rotate_stacks(a, b, cheapest);
	ft_pa(a, b);
}

void	ft_push_everybody_in_b(t_dlist *a, t_dlist *b)
{
	int	median;

	median = ft_getmedian(a);
	while (a->dlst_len > 3 && !ft_is_sorted_stack(a))
	{
		if (a->p_head->data >= median)
			ft_pb(a, b);
		else
		{
			if (b->dlst_len >= 1)
			{
				ft_pb(a, b);
				ft_rb(b);
			}
			else
				ft_pb(a, b);
		}
	}
}

int	ft_is_empty_stack(t_dlist *stack)
{
	if (!stack->dlst_len)
		return (1);
	return (0);
}
