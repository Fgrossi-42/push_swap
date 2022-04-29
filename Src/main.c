/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:50:52 by fgrossi           #+#    #+#             */
/*   Updated: 2022/04/29 13:21:39 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/swap.h"

int	main(int ac, char **av)
{
	char			**arr;
	t_list			*list;
	t_list			*temp;
	int				index;

	if (do_check(&index, ac, av, &list) == NULL)
		return (0);
	arr = control(list, index);
	temp = list;
	if (check_if_ordered(temp, arr, index) == false)
		return (0);
	choose_how_to_sort(&list, index);
	free(arr);
	return (0);
}
