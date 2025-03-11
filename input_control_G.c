/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control_G.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:10:52 by bifernan          #+#    #+#             */
/*   Updated: 2024/03/18 11:13:11 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checksingle_arg(const char *str)
{
	size_t		i;
	int			is_negative;
	const char	*flag;

	i = 0;
	while (str[i] != '\0')
	{
		is_negative = 0;
		if (!ft_isnumber(str[i]))
			ft_error();
		if (ft_isminus(str[i]) && !ft_isdigit(str[i + 1]))
			ft_error();
		if (ft_isminus(str[i]) && ft_isdigit(str[i -1]))
			ft_error();
		if (ft_isminus(str[i]) && ft_isdigit(str[i + 1]))
		{
			is_negative = 1;
			i++;
		}
		flag = &str[i];
		ft_checknumber(flag, is_negative);
		while (ft_isdigit(str[i]))
		i++;
	}
}

void	ft_checkall_arg(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0])
			ft_error();
		ft_checksingle_arg(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				ft_error();
			j++;
		}
		i++;
	}
}

void	ft_checkinput(int argc, char *argv[])
{
	if (argc == 1)
		exit (0);
	if (argc == 2)
		ft_checklist_string(argv[1]);
	else
		ft_checkall_arg(argc, argv);
}

void	ft_fill_array(char *argv[], int argc, t_dlist *dlst)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_dlstadd_back(dlst, ft_atoi(argv[i]));
		i++;
	}
}

void	ft_get_numbers(int argc, char *argv[], t_dlist *dlst)
{
	char	**array;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc > 2)
		ft_fill_array(argv, argc, dlst);
	else
	{
		array = ft_split(argv[i], ' ');
		if (!array)
			ft_errorlist(&dlst);
		while (array[j] != NULL)
		{
			ft_dlstadd_back(dlst, ft_atoi(array[j]));
			j++;
		}
		ft_deallocate(array, j);
	}
}
