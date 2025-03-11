/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_A.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:41:41 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:56:19 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_stacks_helper(t_dlist *a, t_dlist *b, t_node *cheapest)
{
	if (cheapest->is_in_upper_half && cheapest->target->is_in_upper_half)
	{
		while (cheapest->cost_in_a && cheapest->cost_in_b)
		{
			ft_rr(a, b);
			cheapest->cost_in_a--;
			cheapest->cost_in_b--;
		}
		if (!cheapest->cost_in_b)
			ft_finish_rotating(a, &(cheapest->cost_in_a), &ft_ra);
		else
			ft_finish_rotating(b, &(cheapest->cost_in_b), &ft_rb);
	}
}

void	ft_rotate_stacks(t_dlist *a, t_dlist *b, t_node *cheapest)
{
	ft_rotate_stacks_helper(a, b, cheapest);
	if (cheapest->is_in_lower_half && cheapest->target->is_in_lower_half)
	{
		while (cheapest->cost_in_a && cheapest->cost_in_b)
		{
			ft_rrr(a, b);
			cheapest->cost_in_a--;
			cheapest->cost_in_b--;
		}
		if (!cheapest->cost_in_b)
			ft_finish_rotating(a, &(cheapest->cost_in_a), &ft_rra);
		else
			ft_finish_rotating(b, &(cheapest->cost_in_b), &ft_rrb);
	}
	if (cheapest->is_in_upper_half && cheapest->target->is_in_lower_half)
	{
		ft_finish_rotating(a, &(cheapest->cost_in_a), &ft_rra);
		ft_finish_rotating(b, &(cheapest->cost_in_b), &ft_rb);
	}
	if (cheapest->is_in_lower_half && cheapest->target->is_in_upper_half)
	{
		ft_finish_rotating(a, &(cheapest->cost_in_a), &ft_ra);
		ft_finish_rotating(b, &(cheapest->cost_in_b), &ft_rrb);
	}
}

void	ft_sort_a(t_dlist *a)
{
	t_node	*min;

	ft_set_index(a);
	min = ft_get_min(a);
	if (min->is_in_upper_half)
	{
		while (min->index != 0)
		{
			ft_ra(a);
			ft_set_index(a);
		}
	}
	else
	{
		while (min->index != 0)
		{
			ft_rra(a);
			ft_set_index(a);
		}
	}
}

void	ft_supersmartsort_v4(t_dlist *a, t_dlist *b)
{
	if (a->dlst_len == 1)
		return ;
	else if (a->dlst_len == 2)
		ft_size_2_solver(a);
	else if (a->dlst_len == 3)
		ft_size_3_solver(a);
	else
	{
		ft_push_everybody_in_b(a, b);
		if (!ft_is_sorted_stack(a))
			ft_size_3_solver(a);
		while (b->dlst_len)
		{
			ft_set_index(a);
			ft_set_index(b);
			ft_empty_b(a, b);
		}
		ft_sort_a(a);
	}
}

void	ft_size_2_solver(t_dlist *stack)
{
	if (stack->dlst_len < 2)
		return ;
	if (stack->dlst_len > 2)
		return ;
	if (stack->p_head->data > stack->p_tail->data)
		ft_sa(stack);
}
