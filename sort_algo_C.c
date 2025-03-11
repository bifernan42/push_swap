/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_C.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:42:13 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:58:03 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_cost_in_a(t_dlist *a, t_node *node)
{
	if (node->target->is_in_upper_half)
		node->cost_in_a = node->target->index;
	else
		node->cost_in_a = (int)a->dlst_len - node->target->index;
}

void	ft_set_cost_in_b(t_dlist *b, t_node *node)
{
	if (node->is_in_upper_half)
		node->cost_in_b = node->index;
	else
		node->cost_in_b = (int)b->dlst_len - node->index;
}

void	ft_set_cost(t_dlist *a, t_dlist *b)
{
	t_node	*temp_b;

	temp_b = b->p_head;
	while (temp_b != NULL)
	{
		ft_set_cost_in_a(a, temp_b);
		ft_set_cost_in_b(b, temp_b);
		temp_b->cost = temp_b->cost_in_a + temp_b->cost_in_b;
		temp_b = temp_b->p_next;
	}
}

t_node	*ft_get_cheapest(t_dlist *b)
{
	t_node	*cheapest;
	t_node	*temp_b;

	if (!b->dlst_len)
		return (NULL);
	temp_b = b->p_head;
	cheapest = b->p_head;
	while (temp_b != NULL)
	{
		if (temp_b->cost < cheapest->cost)
			cheapest = temp_b;
		temp_b = temp_b->p_next;
	}
	return (cheapest);
}

void	ft_finish_rotating(t_dlist *stack, int \
*cost_in_stack, void (*f)(t_dlist *))
{
	while (*cost_in_stack)
	{
		f(stack);
		*cost_in_stack -= 1;
	}
}
