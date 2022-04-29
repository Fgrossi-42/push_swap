/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:50:59 by fgrossi           #+#    #+#             */
/*   Updated: 2022/04/29 15:16:32 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/swap.h"

void	solve_500(t_list **a, t_list *b, int index)
{
	t_lis		lis_list;
	t_content	bag;
	int			count;

	lis_list.arr_int = create_arr(*a, index);
	lis_list.lis_ar = lis(lis_list.arr_int, index, &count);
	lis_list.count = count;
	lis_list.clear_arr = calloc(sizeof(int), count);
	lis_list.clear_arr = confront(lis_list, count, (index - 1));
	push_lis(a, &b, lis_list, index);
	control_how_to(a, &b, &bag);
	re_order_a(a);
}

void	control_how_to(t_list **a, t_list **b, t_content *bag)
{
	int		i;
	t_list	*last_a;

	bag->max_lis_a = max_list(*a);
	bag->min_lis_a = min_list(*a);
	bag->max_b = max_list(*b);
	bag->min_b = min_list(*b);
	while (*b)
	{
		last_a = ft_lstlast(*a);
		while (check_for_condition(a, b, *bag))
		{
			if ((*b)->cnt == bag->max_b && (*a)->cnt == min_list(*a)
				&& last_a->cnt == max_list(*a))
				break ;
			if ((*b)->cnt == bag->min_b && (*a)->cnt == min_list(*a)
				&& last_a->cnt == max_list(*a))
				break ;
			i = control_moves(a, b, *bag);
			if (choose(a, b, i, *bag))
				break ;
		}
		push_a(a, b);
	}
}

// int	code(t_list **a, t_list **b, t_content bag)
// {

// }

int	control_moves_util(t_list **a, t_list **b, t_content bag)
{
	int	code;

	if (bag.counter > how_many_ra(a, (*b)->cnt, bag))
		bag.counter = count_moves_ra(a, b, bag, &code);
	back_to_normal_util(a, b, bag);
	if (bag.counter > how_many_rra(a, (*b)->cnt, bag))
		bag.counter = count_moves_rra(a, b, bag, &code);
	back_to_normal_util(a, b, bag);
	if (bag.counter > how_many_rr(a, b, bag))
		bag.counter = count_moves_rr(a, b, bag, &code);
	back_to_normal_util(a, b, bag);
	if (bag.counter > how_many_rrr(a, b, bag))
		bag.counter = count_moves_rrr(a, b, bag, &code);
	back_to_normal_util(a, b, bag);
	if (bag.counter > how_many_rb(a, b, bag))
		bag.counter = count_moves_rb(a, b, bag, &code);
	back_to_normal_util(a, b, bag);
	if (bag.counter > how_many_rrb(a, b, bag))
		bag.counter = count_moves_rrb(a, b, bag, &code);
	back_to_normal_util(a, b, bag);
	if (bag.counter > how_many_sb(a, b, bag))
		bag.counter = count_moves_sb(a, b, bag, &code);
	back_to_normal_sb(b, bag);
	return (code);
}

int	control_moves(t_list **a, t_list **b, t_content bag)
{
	bag.counter = 2147483647;
	bag.cont_b = (*b)->cnt;
	bag.cont_a = (*a)->cnt;
	bag.code = control_moves_util(a, b, bag);
	return (bag.code);
}
