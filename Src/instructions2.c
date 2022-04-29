/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:50:36 by fgrossi           #+#    #+#             */
/*   Updated: 2022/04/29 13:21:36 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/swap.h"

void	swap_a(t_list *list, bool allow)
{
	int	temp;

	if (allow)
		write(1, "sa\n", 3);
	if (!list)
		return ;
	else if (!list->next)
		return ;
	temp = list->cnt;
	list->cnt = list->next->cnt;
	list->next->cnt = temp;
}

void	swap_b(t_list *list, bool allow)
{
	int	temp;

	if (allow)
		write(1, "sb\n", 3);
	if (!list)
		return ;
	else if (!list->next)
		return ;
	temp = list->cnt;
	list->cnt = list->next->cnt;
	list->next->cnt = temp;
}

void	swap_a_b(t_list *list, bool allow)
{
	if (allow)
		write(1, "ss\n", 3);
	if (list)
	{
		swap_a(list, false);
		swap_b(list, false);
	}
	else
		return ;
}

void	push_a(t_list **list, t_list **listb)
{
	t_list	*temp;

	write(1, "pa\n", 3);
	if (*listb)
	{
		temp = *listb;
		*listb = (*listb)->next;
		temp->next = *list;
		*list = temp;
	}
	else
		return ;
}

void	push_b(t_list **listb, t_list **list)
{
	t_list	*temp;

	write(1, "pb\n", 3);
	if (*list)
	{
		temp = *list;
		*list = (*list)->next;
		temp->next = *listb;
		*listb = temp;
	}
	else
		return ;
}
