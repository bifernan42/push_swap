/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control_B.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:48:20 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:47:13 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

size_t	ft_digitslen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0' && ft_isnumber(*str))
	{
		count++;
		str++;
	}
	return (count);
}

size_t	ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	printed;

	printed = 0;
	if (!dst || !src || !n)
		return (printed);
	while (*src != '\0' && n > 0)
	{
		*dst++ = *src++;
		n--;
		printed++;
	}
	*dst = '\0';
	return (printed);
}		

int	ft_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	ft_min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}
