/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:51:18 by fgrossi           #+#    #+#             */
/*   Updated: 2022/04/29 13:21:23 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/swap.h"

int	count_moves_ra(t_list **a, t_list **b, t_content bag, int *c)
{
	int	temp;

	(*c) = 1;
	back_to_norm(a, b, bag, c);
	temp = how_many_ra(a, (*b)->cnt, bag);
	back_to_norm(a, b, bag, c);
	return (temp);
}

int	count_moves_rra(t_list **a, t_list **b, t_content bag, int *c)
{
	int	temp;

	(*c) = 2;
	back_to_norm(a, b, bag, c);
	temp = how_many_rra(a, (*b)->cnt, bag);
	back_to_norm(a, b, bag, c);
	return (temp);
}

int	count_moves_rr(t_list **a, t_list **b, t_content bag, int *c)
{
	int	temp;

	(*c) = 3;
	back_to_norm(a, b, bag, c);
	temp = how_many_rr(a, b, bag);
	back_to_norm(a, b, bag, c);
	return (temp);
}

int	count_moves_rrr(t_list **a, t_list **b, t_content bag, int *c)
{
	int	temp;

	(*c) = 4;
	back_to_norm(a, b, bag, c);
	temp = how_many_rrr(a, b, bag);
	back_to_norm(a, b, bag, c);
	return (temp);
}

void	back_to_normal_util(t_list **a, t_list **b, t_content bag)
{
	while ((*a)->cnt != bag.cont_a)
		rotate_a(a, false);
	while ((*b)->cnt != bag.cont_b)
		rotate_b(b, false);
}
