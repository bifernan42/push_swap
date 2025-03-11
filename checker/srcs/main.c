/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:03:37 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/15 15:05:54 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

int	ft_is_empty_stack(t_dlist *stack)
{
	if (!stack->dlst_len)
		return (1);
	return (0);
}

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

void	ft_get_instructions(char *line, t_dlist *a, t_dlist *b)
{
	if (!line)
		return ;
	ft_apply_instructions(line, a, b);
}

void	ft_apply_instructions(char *line, t_dlist *a, t_dlist *b)
{
	if (ft_memcmp("sa\n", line, 4))
		ft_sa(a);
	else if (ft_memcmp("sb\n", line, 4))
		ft_sb(b);
	else if (ft_memcmp("ra\n", line, 4))
		ft_ra(a);
	else if (ft_memcmp("rb\n", line, 4))
		ft_rb(b);
	else if (ft_memcmp("rr\n", line, 4))
		ft_rr(a, b);
	else if (ft_memcmp("rra\n", line, 5))
		ft_rra(a);
	else if (ft_memcmp("rrb\n", line, 5))
		ft_rrb(b);
	else if (ft_memcmp("rrr\n", line, 5))
		ft_rrr(a, b);
	else if (ft_memcmp("ss\n", line, 4))
		ft_ss(a, b);
	else if (ft_memcmp("pa\n", line, 4))
		ft_pa(a, b);
	else if (ft_memcmp("pb\n", line, 4))
		ft_pb(a, b);
	else
		ft_instructions_error(line, a, b);
}

int	main(int argc, char *argv[])
{
	t_dlist	*a;
	t_dlist	*b;
	char	*line;

	ft_checkinput(argc, argv);
	a = ft_dlstnew();
	if (!a)
		exit (1);
	ft_get_numbers(argc, argv, a);
	b = ft_dlstnew();
	ft_stack_error(a, b);
	while (1)
	{
		line = get_next_line(1);
		ft_get_instructions(line, a, b);
		if (!line)
			break ;
		free(line);
	}
	if (!ft_is_sorted_stack(a) || !ft_is_empty_stack(b))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_free_stacks(a, b);
}
