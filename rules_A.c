/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_A.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:52:46 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:55:21 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_dlist *dlst)
{
	t_node	*temp;

	if (!dlst || dlst->dlst_len < 2)
		return ;
	temp = dlst->p_head;
	dlst->p_head = temp->p_next;
	if (dlst->p_head->p_next != NULL)
		dlst->p_head->p_next->p_prev = temp;
	temp->p_next = dlst->p_head->p_next;
	temp->p_prev = dlst->p_head;
	dlst->p_head->p_next = temp;
	dlst->p_head->p_prev = NULL;
}

void	ft_push(t_dlist *stack_from, t_dlist *stack_to)
{
	t_node	*temp;

	if (!stack_from || !stack_to || !stack_from->dlst_len)
		return ;
	temp = stack_from->p_head;
	if (stack_from->dlst_len == 1)
	{
		stack_from->p_head = NULL;
		stack_from->p_tail = NULL;
	}
	else
	{
		stack_from->p_head = temp->p_next;
		temp->p_next->p_prev = NULL;
	}
	temp->p_next = stack_to->p_head;
	if (!stack_to->p_head)
		stack_to->p_tail = temp;
	else
		stack_to->p_head->p_prev = temp;
	stack_to->p_head = temp;
	stack_from->dlst_len--;
	stack_to->dlst_len++;
}

void	ft_rotate(t_dlist *stack)
{
	t_node	*temp;

	if (!stack || stack->dlst_len < 2)
		return ;
	temp = stack->p_head;
	stack->p_head = temp->p_next;
	stack->p_head->p_prev = NULL;
	stack->p_tail->p_next = temp;
	temp->p_prev = stack->p_tail;
	temp->p_next = NULL;
	stack->p_tail = temp;
	if (stack->dlst_len == 2)
	{
		stack->p_head->p_next = stack->p_tail;
		stack->p_tail->p_prev = stack->p_head;
	}
}

void	ft_rrotate(t_dlist *stack)
{
	t_node	*temp_tail;

	if (!stack || stack->dlst_len < 2)
		return ;
	temp_tail = stack->p_tail;
	stack->p_tail = temp_tail->p_prev;
	stack->p_tail->p_next = NULL;
	temp_tail->p_next = stack->p_head;
	temp_tail->p_prev = NULL;
	stack->p_head->p_prev = temp_tail;
	stack->p_head = temp_tail;
	if (stack->dlst_len == 2)
	{
		stack->p_head->p_next = stack->p_tail;
		stack->p_tail->p_prev = stack->p_head;
	}
}

void	ft_pa(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}
