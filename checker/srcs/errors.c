/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:57:57 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/15 15:05:33 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_deallocate(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i -= 1;
	}
	free(array);
}

void	ft_stack_error(t_dlist *a, t_dlist *b)
{
	if (!b)
	{
		ft_errorlist(&a);
		exit (1);
	}
}

void	ft_instructions_error(char *line, t_dlist *a, t_dlist *b)
{
	write(1, "Error\n", 6);
	free(line);
	ft_free_stacks(a, b);
	exit(1);
}

void	ft_free_stacks(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_dlstfree(&stack_a);
	ft_dlstfree(&stack_b);
}
