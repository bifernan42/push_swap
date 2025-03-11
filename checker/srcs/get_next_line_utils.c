/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:32:34 by bifernan          #+#    #+#             */
/*   Updated: 2024/01/30 21:06:18 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_snc(char *dst, const char *src, size_t n, int is_line)
{
	if (!dst || !src || !n)
		return ;
	while (n > 0)
	{
		*dst++ = *src++;
		n--;
	}
	if (is_line)
		*dst = '\0';
}

void	*ft_memset(char *s, int c, size_t n)
{
	char	*ptr_to_memory;

	ptr_to_memory = (char *)s;
	while (n > 0)
	{
		*ptr_to_memory = c;
		ptr_to_memory++;
		n--;
	}
	return (s);
}

t_llst	*ft_newl(void)
{
	t_llst	*dlst;

	dlst = (t_llst *)malloc(sizeof(t_llst));
	if (!dlst)
		return (NULL);
	dlst->dlst_len = 0;
	dlst->p_head = NULL;
	dlst->p_tail = NULL;
	return (dlst);
}

void	ft_addfront(t_llst *dlst, char *c, int b1_size)
{
	t_nod	*node;

	if (!dlst || !c)
		return ;
	node = (t_nod *)malloc(sizeof(t_nod));
	if (!node)
		return ;
	ft_snc(node->c, c, b1_size, 0);
	node->p_next = NULL;
	node->p_prev = NULL;
	if (dlst->dlst_len == 0)
	{
		dlst->p_head = node;
		dlst->p_tail = node;
	}
	else
	{
		node->p_prev = NULL;
		node->p_next = dlst->p_head;
		dlst->p_head->p_prev = node;
		dlst->p_head = node;
	}
	dlst->dlst_len += 1;
}

void	ft_lclear(t_llst *dlst)
{
	t_nod	*temp;

	if (!dlst)
		return ;
	if (!dlst->p_head)
	{
		free(dlst);
		return ;
	}
	else
	{
		temp = dlst->p_head;
		while (temp)
		{
			temp = temp->p_next;
			free(dlst->p_head);
			dlst->p_head = temp;
			dlst->dlst_len--;
		}
		free(dlst);
	}
}
