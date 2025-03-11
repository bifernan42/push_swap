/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control_D.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:38:17 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/14 13:49:22 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_bust_zeroes_v2(const char *str)
{
	char	*rez;
	size_t	i;

	i = 0;
	while (ft_isnumber(str[i]) && str[i] != '\0')
		i++;
	while (*str == '0' && i > 1)
	{
		i--;
		str++;
	}
	rez = (char *)str;
	return (rez);
}

char	*ft_nbrtr(const char *str)
{
	size_t	nbr_len;
	char	*number;
	char	*nbr;

	nbr = ft_bust_zeroes_v2(str);
	nbr_len = ft_nbrlen(nbr);
	number = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!number)
		return (NULL);
	ft_strncpy(number, nbr, nbr_len);
	return (number);
}

void	ft_nbrchr(const char *str, char **number)
{
	if (!str || !*number)
		exit (1);
	while (*str != '\0')
	{
		if (ft_atoi(*number) == ft_atoi(str))
		{
			free(*number);
			ft_error();
		}
		while (ft_isnumber(*str) && *str != '\0')
			str++;
		while (!ft_isnumber(*str) && *str != '\0')
			str++;
	}
	free(*number);
	*number = NULL;
}

size_t	ft_nbrlen(const char *str)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = 0;
	while (ft_isnumber(str[len]) && str[len] != '\0')
		len++;
	while (len > 1 && *str == '0')
	{
		len--;
		str++;
	}
	while (*str != '\0' && ft_isnumber(*str))
	{
		count++;
		str++;
	}
	return (count);
}

size_t	ft_nbrlen_v2(const char **str)
{
	size_t	count;
	int		i;
	char	*flag;

	count = 0;
	i = 0;
	if (ft_strlen(*str) > 1 && **str == '0')
	{
		while (**str == '0')
			*str += 1;
	}
	flag = (char *)*str;
	while (flag[i] != '\0' && ft_isnumber(flag[i]))
	{
		count++;
		i++;
	}
	return (count);
}
