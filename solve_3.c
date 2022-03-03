/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:51:03 by fgrossi           #+#    #+#             */
/*   Updated: 2022/03/03 12:51:03 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	how_many_ra(t_list **a, int num, t_content bag)
{
	int		i;
	t_list	*last_a;

	i = 0;
	bag.ind = 500;
	last_a = ft_lstlast(*a);
	while (!((*a)->cnt > num && last_a->cnt < num))
	{
		if (num == bag.max_b && num > bag.max_lis_a)
		{
			if ((*a)->cnt == min_list(*a) && last_a->cnt == max_list(*a))
				return (i);
		}
		if (num == bag.min_b && num < bag.min_lis_a)
		{
			if ((*a)->cnt == min_list(*a) && last_a->cnt == max_list(*a))
				return (i);
		}
		rotate_a(a, false);
		last_a = ft_lstlast(*a);
		if (i > bag.ind)
			return (i);
		i++;
	}
	return (i);
}

int	how_many_rra(t_list **a, int num, t_content bag)
{
	int		i;
	t_list	*last_a;

	i = 0;
	bag.ind = 500;
	last_a = ft_lstlast(*a);
	while (!((*a)->cnt > num && last_a->cnt < num))
	{
		if (num == bag.max_b && num > bag.max_lis_a)
		{
			if ((*a)->cnt == min_list(*a) && last_a->cnt == max_list(*a))
				return (i);
		}
		if (num == bag.min_b && num < bag.min_lis_a)
		{
			if ((*a)->cnt == min_list(*a) && last_a->cnt == max_list(*a))
				return (i);
		}
		rotate_reverse_a(a, false);
		last_a = ft_lstlast(*a);
		if (i > bag.ind)
			return (i);
		i++;
	}
	return (i);
}

int	how_many_rb(t_list **a, t_list **b, t_content bag)
{
	int		i;
	t_list	*last_a;

	i = 0;
	bag.ind = 500;
	last_a = ft_lstlast(*a);
	while (!((*a)->cnt > (*b)->cnt && last_a->cnt < (*b)->cnt))
	{
		if ((*b)->cnt == bag.max_b && (*b)->cnt > bag.max_lis_a)
		{
			if ((*a)->cnt == min_list(*a) && last_a->cnt == max_list(*a))
				return (i);
		}
		if ((*b)->cnt == bag.min_b && (*b)->cnt < bag.min_lis_a)
		{
			if ((*a)->cnt == min_list(*a) && last_a->cnt == max_list(*a))
				return (i);
		}
		rotate_b(b, false);
		last_a = ft_lstlast(*a);
		if (i > bag.ind)
			return (i);
		i++;
	}
	return (i);
}

int	how_many_rrb(t_list **a, t_list **b, t_content bag)
{
	int		i;
	t_list	*last_a;

	i = 0;
	bag.ind = 500;
	last_a = ft_lstlast(*a);
	while (!((*a)->cnt > (*b)->cnt && last_a->cnt < (*b)->cnt))
	{
		if ((*b)->cnt == bag.max_b && (*b)->cnt > bag.max_lis_a)
		{
			if ((*a)->cnt == min_list(*a) && last_a->cnt == max_list(*a))
				return (i);
		}
		if ((*b)->cnt == bag.min_b && (*b)->cnt < bag.min_lis_a)
		{
			if ((*a)->cnt == min_list(*a) && last_a->cnt == max_list(*a))
				return (i);
		}
		rotate_reverse_b(b, false);
		last_a = ft_lstlast(*a);
		if (i > bag.ind)
			return (i);
		i++;
	}
	return (i);
}

int	how_many_rr(t_list **a, t_list **b, t_content bag)
{
	int		i;
	t_list	*last_a;

	i = 0;
	bag.ind = 500;
	last_a = ft_lstlast(*a);
	while (!((*a)->cnt > (*b)->cnt && last_a->cnt < (*b)->cnt))
	{
		if ((*b)->cnt == bag.max_b && (*b)->cnt > bag.max_lis_a)
		{
			if ((*a)->cnt == min_list(*a) && last_a->cnt == max_list(*a))
				return (i);
		}
		if ((*b)->cnt == bag.min_b && (*b)->cnt < bag.min_lis_a)
		{
			if ((*a)->cnt == min_list(*a) && last_a->cnt == max_list(*a))
				return (i);
		}
		rotate_a_b(a, b, false);
		last_a = ft_lstlast(*a);
		if (i > bag.ind)
			return (i);
		i++;
	}
	return (i);
}
