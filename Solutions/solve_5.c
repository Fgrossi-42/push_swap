/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:51:14 by fgrossi           #+#    #+#             */
/*   Updated: 2022/04/29 13:21:21 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/swap.h"

int	how_many_rrr(t_list **a, t_list **b, t_content bag)
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
		rotate_reverse_a_b(a, b, false);
		last_a = ft_lstlast(*a);
		if (i > bag.ind)
			return (i);
		i++;
	}
	return (i);
}

int	how_many_sb(t_list **a, t_list **b, t_content bag)
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
		swap_b((*b), false);
		last_a = ft_lstlast(*a);
		if (i > 2)
			return (501);
		i++;
	}
	return (i);
}

int	choose_how_to(t_list *list, int find)
{
	int		*arr;
	int		i;
	t_list	*temp;
	int		count_arr;

	i = 0;
	count_arr = 0;
	temp = list;
	arr = malloc(sizeof(int) * 1);
	while (list->cnt != find && list)
	{
		list = list->next;
		i++;
	}
	while (temp)
	{
		temp = temp->next;
		count_arr++;
	}
	if (i < count_arr / 2)
		return (1);
	else
		return (0);
}
