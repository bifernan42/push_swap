/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control_C.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:54:06 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:48:38 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	rez;

	i = 0;
	sign = 1;
	rez = 0;
	while (((str[i] > 8 && str[i] < 14) || str[i] == 32) && str[i] != '\0')
		i++;
	while ((str[i] == '-' || str[i] == '+') && str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		rez = rez * 10 + (str[i] - '0');
		i++;
	}
	return (rez * sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	rez;

	i = 0;
	sign = 1;
	rez = 0;
	while (((str[i] > 8 && str[i] < 14) || str[i] == 32) && str[i] != '\0')
		i++;
	while ((str[i] == '-' || str[i] == '+') && str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		rez = rez * 10 + (str[i] - '0');
		i++;
	}
	return (rez * sign);
}

char	*ft_bust_zeroes(const char *str)
{
	size_t	nbr_len;
	char	*number;

	number = (char *)str;
	nbr_len = ft_nbrlen(number);
	while (nbr_len > 1 && *number == '0')
	{
		number++;
		nbr_len--;
	}
	return (number);
}

void	ft_checknumber(const char *number, int is_negative)
{
	long	int_max_abs;
	long	int_min_abs;

	int_max_abs = 2147483647;
	int_min_abs = int_max_abs + 1;
	if (is_negative && (ft_atol(number) > int_min_abs))
		ft_error();
	if (!is_negative && (ft_atol(number) > int_max_abs))
		ft_error();
}
