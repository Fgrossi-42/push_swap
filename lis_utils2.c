/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:50:49 by fgrossi           #+#    #+#             */
/*   Updated: 2022/03/03 12:50:49 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

unsigned int	count_offset(t_lis lis_list, int count, int index)
{
	unsigned int	i;

	i = 0;
	while (index >= 0)
	{
		if (lis_list.lis_ar[index] == count)
			return (i);
		else
		{
			i++;
			index--;
		}
	}
	return (0);
}

void	push_lis(t_list **a, t_list **b, t_lis lis_list, int index)
{
	t_list	*temp;
	int		i;

	temp = *a;
	i = 0;
	while ((i < index))
	{
		if ((i >= lis_list.count) && temp->cnt == 0)
		{
			push_b(b, a);
			index--;
		}
		else if (temp->cnt == lis_list.clear_arr[i])
		{
			rotate_a(a, true);
			i++;
		}
		else
		{
			push_b(b, a);
			index--;
		}
		temp = *a;
	}
}

int	min_list(t_list *a)
{
	int	temp;

	temp = 2147483647;
	while (a)
	{
		if (temp >= a->cnt)
			temp = a->cnt;
		a = a->next;
	}
	return (temp);
}

int	max_list(t_list *a)
{
	int	temp;

	temp = -2147483648;
	while (a)
	{
		if (temp <= a->cnt)
			temp = a->cnt;
		a = a->next;
	}
	return (temp);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	last = lst;
	return (last);
}
