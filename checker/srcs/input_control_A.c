/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control_A.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:45:27 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:46:41 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(char c)
{
	return (c == ' ');
}

int	ft_isminus(char c)
{
	return (c == '-');
}

int	ft_isnumber(char c)
{
	return (ft_isdigit(c) || ft_isminus(c));
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*ss1 != *ss2)
			return (0);
		ss1++;
		ss2++;
		n--;
	}
	if (n)
		return (0);
	return (1);
}
