/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:50:14 by fgrossi           #+#    #+#             */
/*   Updated: 2022/04/29 13:21:00 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/swap.h"

int	check_double(char **av, int argc)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < argc)
	{
		k = i + 1;
		while (k < argc)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[k]))
				return (ft_putstr("Error_double\n"));
			k++;
		}
		i++;
	}
	return (1);
}

bool	check_pure_questo(char *str, int k)
{
	int	num;

	num = ft_atoi(str);
	if (!num && str[k] != '0')
	{
		return (true);
	}
	else if (str[k] == '0' && (str[k + 1] == '-' || str[k + 1] == '+'))
		return (true);
	else
		return (false);
}

int	check_integers(char **av, int argc)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (++i < argc)
	{
		k = 0;
		while (av[i][k])
		{
			if (av[i][k] == 43 || av[i][k] == 45 ||
			(av[i][k] >= 48 && av[i][k] <= 57))
				k++;
			else
				return (ft_putstr("Error_integer\n"));
		}
		if (check_pure_questo(av[i], 0) == true)
			return (ft_putstr("Error_integer_bool\n"));
	}
	return (1);
}

int	check_size(char **av, int argc)
{
	int				i;
	long long int	a;

	i = 0;
	while (i < argc)
	{
		a = ft_atoi(av[i]);
		if (a > 2147483647 || a < -2147483648)
			return (ft_putstr("Error_size\n"));
		i++;
	}
	return (1);
}

int	check_all(char **arr, int argc)
{
	int	i;

	i = 0;
	i += check_integers(arr, argc);
	if (i == 1)
		i += check_size(arr, argc);
	if (i == 2)
		i += check_double(arr, argc);
	if (i == 3)
		return (1);
	else
		return (0);
}
