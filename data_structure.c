/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:35:02 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:59:49 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstfree(t_dlist **dlst)
{
	t_node	*temp;

	if (!*dlst)
		return ;
	temp = (*dlst)->p_head;
	while (temp != NULL)
	{
		temp = (*dlst)->p_head->p_next;
		free((*dlst)->p_head);
		(*dlst)->p_head = temp;
		(*dlst)->dlst_len -= 1;
	}
	free(*dlst);
	*dlst = NULL;
}

void	ft_errorlist(t_dlist **dlst)
{
	ft_dlstfree(dlst);
	exit (1);
}

t_dlist	*ft_dlstnew(void)
{
	t_dlist	*dlst;

	dlst = (t_dlist *)malloc(sizeof(t_dlist));
	if (!dlst)
		return (NULL);
	dlst->dlst_len = 0;
	dlst->p_head = NULL;
	dlst->p_tail = NULL;
	return (dlst);
}

void	ft_dlstadd_front(t_dlist *dlst, int data)
{
	t_node	*new;

	if (!dlst)
		return ;
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		ft_errorlist(&dlst);
	new->data = data;
	new->p_next = NULL;
	new->p_prev = NULL;
	if (dlst->dlst_len == 0)
	{
		dlst->p_head = new;
		dlst->p_tail = new;
	}
	else
	{
		dlst->p_head->p_prev = new;
		new->p_next = dlst->p_head;
		dlst->p_head = new;
	}
	dlst->dlst_len += 1;
}

void	ft_dlstadd_back(t_dlist *dlst, int data)
{
	t_node	*new;

	if (!dlst)
		return ;
	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	new->p_next = NULL;
	new->p_prev = NULL;
	if (!new)
		ft_errorlist(&dlst);
	if (!dlst->dlst_len)
	{
		dlst->p_head = new;
		dlst->p_tail = new;
	}
	else
	{
		dlst->p_tail->p_next = new;
		new->p_prev = dlst->p_tail;
		dlst->p_tail = new;
	}
	dlst->dlst_len += 1;
}
