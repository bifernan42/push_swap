/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_B.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:41:59 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:56:50 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index(t_dlist *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = stack->p_head;
	if (!temp)
		return ;
	while (temp != NULL)
	{
		temp->index = i;
		if (temp->index < (int)stack->dlst_len / 2)
		{
			temp->is_in_upper_half = 1;
			temp->is_in_lower_half = 0;
		}
		else
		{	
			temp->is_in_upper_half = 0;
			temp->is_in_lower_half = 1;
		}
		temp = temp->p_next;
		i++;
	}
}

t_node	*ft_get_max(t_dlist *a)
{
	t_node	*max;
	t_node	*temp;

	temp = a->p_head;
	max = temp;
	while (temp != NULL)
	{
		if (temp->data > max->data)
			max = temp;
		temp = temp->p_next;
	}
	return (max);
}

t_node	*ft_get_min(t_dlist *a)
{
	t_node	*min;
	t_node	*temp;

	temp = a->p_head;
	min = temp;
	while (temp != NULL)
	{
		if (temp->data < min->data)
			min = temp;
		temp = temp->p_next;
	}
	return (min);
}

void	ft_get_target_node(t_dlist *a, t_node *node_b)
{
	t_node	*temp_a;

	temp_a = a->p_head;
	node_b->target = ft_get_max(a);
	if (node_b->data > node_b->target->data)
	{
		node_b->target = ft_get_min(a);
		return ;
	}
	while (temp_a != NULL)
	{
		if (temp_a->data > node_b->data && temp_a->data < node_b->target->data)
			node_b->target = temp_a;
		temp_a = temp_a->p_next;
	}
}

void	ft_set_target_node(t_dlist *a, t_dlist *b)
{
	t_node	*temp_b;

	temp_b = b->p_head;
	while (temp_b != NULL)
	{
		ft_get_target_node(a, temp_b);
		temp_b = temp_b->p_next;
	}
}
