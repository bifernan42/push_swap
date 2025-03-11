/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_E.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:42:56 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:59:14 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted_stack(t_dlist *stack)
{
	t_node	*temp1;
	t_node	*temp2;

	if (stack->dlst_len == 0 || stack->dlst_len == 1)
		return (1);
	temp1 = stack->p_head;
	while (temp1->p_next != NULL)
	{
		temp2 = temp1->p_next;
		while (temp2 != NULL)
		{
			if (temp2->data < temp1->data)
				return (0);
			temp2 = temp2->p_next;
		}
		temp1 = temp1->p_next;
	}
	return (1);
}

int	ft_get_max_index(int *tab)
{
	int	max;
	int	i;
	int	index;

	index = 0;
	i = 0;
	max = tab[0];
	while (i < 3)
	{
		if (max < tab[i])
		{
			max = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	ft_get_min_index(int *tab)
{
	int	min;
	int	i;
	int	index;

	index = 0;
	i = 0;
	min = tab[0];
	while (i < 3)
	{
		if (min > tab[i])
		{
			min = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	ft_3_solver_helper(t_dlist *a)
{
	ft_sa(a);
	ft_rra(a);
}

void	ft_size_3_solver(t_dlist *a)
{
	int	tab[3];
	int	min_index;
	int	max_index;

	tab[0] = a->p_head->data;
	tab[1] = a->p_head->p_next->data;
	tab[2] = a->p_tail->data;
	min_index = ft_get_min_index(tab);
	max_index = ft_get_max_index(tab);
	if (min_index == 0 && max_index == 2)
		return ;
	if (min_index == 1 && max_index == 2)
		ft_sa(a);
	if (min_index == 2 && max_index == 1)
		ft_rra(a);
	if (min_index == 2 && max_index == 0)
		ft_3_solver_helper(a);
	if (min_index == 1 && max_index == 0)
		ft_ra(a);
	if (min_index == 0 && max_index == 1)
	{
		ft_rra(a);
		ft_sa(a);
	}
}
