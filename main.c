/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:57:33 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:54:19 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stacks(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_dlstfree(&stack_a);
	ft_dlstfree(&stack_b);
}
/*
#include <stdio.h>
void	ft_printstack(t_dlist *stack_a, t_dlist *stack_b)
{
	int	diffsize;
	int	to_print;
	t_node	*temp1;
	t_node	*temp2;
	
	diffsize = stack_a->dlst_len - stack_b->dlst_len;
	temp1 = stack_a->p_head;
	temp2 = stack_b->p_head;
	if (diffsize == 0)
	{
		to_print = stack_a->dlst_len;
		while (to_print > 0)
		{
			printf("%d   %d\n", temp1->data, temp2->data);
			to_print--;
			temp1 = temp1->p_next;
			temp2 = temp2->p_next;
		}
		printf("_   _\n");
	}
	else if (diffsize < 0)
	{	
		to_print = stack_b->dlst_len;
		while (diffsize < 0)
		{
			printf("    %d\n", temp2->data);
			diffsize++;
			to_print--;
			temp2 = temp2->p_next;
		}
		while (to_print > 0)
		{
			printf("%d   %d\n", temp1->data, temp2->data);
			to_print--;
			temp1 = temp1->p_next;
			temp2 = temp2->p_next;
		}
		printf("_   _\n");
	}	
	else
	{
		
		to_print = stack_a->dlst_len;
		while (diffsize > 0)
		{
			printf("%d    \n", temp1->data);
			diffsize--;
			to_print--;
			temp1 = temp1->p_next;
		}
		while (to_print > 0)
		{
			printf("%d   %d\n", temp1->data, temp2->data);
			to_print--;
			temp1 = temp1->p_next;
			temp2 = temp2->p_next;
		}
		printf("_   _\n");
	}
}*/	

int	main(int argc, char *argv[])
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	ft_checkinput(argc, argv);
	stack_a = ft_dlstnew();
	if (!stack_a)
		exit (1);
	ft_get_numbers(argc, argv, stack_a);
	stack_b = ft_dlstnew();
	if (!stack_b)
	{
		ft_errorlist(&stack_a);
		exit (1);
	}
	ft_supersmartsort_v4(stack_a, stack_b);
	ft_free_stacks(stack_a, stack_b);
	return (0);
}
