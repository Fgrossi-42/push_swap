/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:51:09 by fgrossi           #+#    #+#             */
/*   Updated: 2022/04/29 13:21:18 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/swap.h"

void	re_order_a(t_list **a)
{
	while ((*a)->cnt != min_list(*a))
	{
		if (choose_how_to(*a, min_list(*a)))
			rotate_a(a, true);
		else
			rotate_reverse_a(a, true);
	}
}

void	back_to_norm(t_list **a, t_list **b, t_content bag, int *c)
{
	while ((*a)->cnt != bag.cont_a || (*b)->cnt != bag.cont_b)
	{
		if ((*c) == 1)
			rotate_reverse_a(a, false);
		else if ((*c) == 2)
			rotate_a(a, false);
		else if ((*c) == 3)
			rotate_reverse_a_b(a, b, false);
		else if ((*c) == 4)
			rotate_a_b(a, b, false);
		else if ((*c) == 5)
			rotate_reverse_b(b, false);
		else if ((*c) == 6)
			rotate_b(b, false);
		else if ((*c) == 7)
			swap_b((*b), false);
	}
}

bool	choose(t_list **a, t_list **b, int i, t_content bag)
{
	if (i == 1)
		rotate_a(a, true);
	else if (i == 2)
		rotate_reverse_a(a, true);
	else if (i == 3)
		rotate_a_b(a, b, true);
	else if (i == 4)
		rotate_reverse_a_b(a, b, true);
	else if (i == 5)
		rotate_b(b, true);
	else if (i == 6)
		rotate_reverse_b(b, true);
	else if (i == 7)
		swap_b((*b), true);
	if (check_for_condition(a, b, bag))
		return (false);
	else
		return (true);
}

bool	check_for_condition(t_list **a, t_list **b, t_content bag)
{
	int	temp_last;
	int	temp_a;
	int	temp_b;

	temp_a = (*a)->cnt;
	temp_b = (*b)->cnt;
	temp_last = ft_lstlast(*a)->cnt;
	if (temp_b == bag.max_b && temp_b > bag.max_lis_a)
	{
		if ((*a)->cnt == min_list(*a) && temp_last == max_list(*a))
			return (false);
		else
			return (true);
	}
	if (temp_b == bag.min_b && temp_b < bag.min_lis_a)
	{
		if ((*a)->cnt == min_list(*a) && temp_last == max_list(*a))
			return (false);
		else
			return (true);
	}
	else if (!(temp_a > temp_b && temp_last < temp_b))
		return (true);
	else
		return (false);
}
