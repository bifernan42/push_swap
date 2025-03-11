/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control_E.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:52:09 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/18 11:16:34 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_unicheck(const char *str)
{
	char	*flag;
	size_t	i;

	i = 0;
	flag = NULL;
	while (str[i] != '\0')
	{
		flag = ft_nbrtr(&str[i]);
		if (!flag)
			exit(1);
		while (ft_isnumber(str[i]) && str[i] != '\0')
			i++;
		while (!ft_isnumber(str[i]) && str[i] != '\0')
			i++;
		ft_nbrchr(&str[i], &flag);
	}
}

void	checklist_string_helper(const char *str, int *i)
{
	if (!ft_isnumber(str[*i]))
		ft_error();
	if (ft_isminus(str[*i]) && *i > 0 && ft_isdigit(str[*i - 1]))
		ft_error();
	if (ft_isminus(str[*i]) && !ft_isdigit(str[*i + 1]))
		ft_error();
}

void	ft_checklist_string(const char *str)
{
	int			i;
	int			is_negative;
	const char	*flag;

	i = 0;
	if (!str[i])
		ft_error();
	while (str[i] != '\0')
	{
		is_negative = 0;
		checklist_string_helper(str, &i);
		if (ft_isminus(str[i]) && ft_isdigit(str[i + 1]))
		{
			is_negative = 1;
			i++;
		}
		flag = &str[i];
		ft_checknumber(flag, is_negative);
		while (ft_isdigit(str[i]))
			i++;
		if (ft_isspace(str[i]) && ft_isnumber(str[i + 1]))
			i++;
	}
	ft_unicheck(str);
}
