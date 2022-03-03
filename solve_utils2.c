/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:51:21 by fgrossi           #+#    #+#             */
/*   Updated: 2022/03/03 12:51:21 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	back_to_normal_sb(t_list **b, t_content bag)
{
	while ((*b)->cnt != bag.cont_b)
		swap_b((*b), false);
}

int	count_moves_rb(t_list **a, t_list **b, t_content bag, int *c)
{
	int	temp;

	(*c) = 5;
	back_to_norm(a, b, bag, c);
	temp = how_many_rb(a, b, bag);
	back_to_norm(a, b, bag, c);
	return (temp);
}

int	count_moves_rrb(t_list **a, t_list **b, t_content bag, int *c)
{
	int	temp;

	(*c) = 6;
	back_to_norm(a, b, bag, c);
	temp = how_many_rrb(a, b, bag);
	back_to_norm(a, b, bag, c);
	return (temp);
}

int	count_moves_sb(t_list **a, t_list **b, t_content bag, int *c)
{
	int	temp;

	(*c) = 7;
	back_to_norm(a, b, bag, c);
	temp = how_many_sb(a, b, bag);
	back_to_norm(a, b, bag, c);
	return (temp);
}
