/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:50:41 by fgrossi           #+#    #+#             */
/*   Updated: 2022/03/03 12:50:41 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int	*confront(t_lis lis_list, int count, int index)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (count > 0)
	{
		i = count_offset(lis_list, count, index);
		index = index - i;
		lis_list.clear_arr[count - 1] = lis_list.arr_int[index];
		count -= 1;
	}
	return (lis_list.clear_arr);
}

int	*create_arr(t_list *list, int i)
{
	int		*arr;
	t_list	*temp;

	temp = list;
	arr = malloc(sizeof(int) * i);
	i = 0;
	while (temp)
	{
		arr[i++] = (temp->cnt);
		temp = temp->next;
	}
	return (arr);
}

int	*fill_arr_lis(int *arr, int n)
{
	int	i;

	i = 0;
	arr = calloc(sizeof(int), n);
	while (i < n)
	{
		arr[i] = 1;
		i++;
	}
	return (arr);
}

unsigned int	max_elements(int *lis, int n)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	i = 0;
	while (i < n)
	{
		if (lis[i] > count)
		{
			count = lis[i];
		}
		i++;
	}
	free (lis);
	return (count);
}

int	*lis(int *arr, int n, int *count)
{
	int	*lis;
	int	*array;
	int	i;
	int	j;

	lis = fill_arr_lis(lis, n);
	array = fill_arr_lis(array, n);
	i = 0;
	while (++i < n)
	{
		j = -1;
		while (++j < i)
		{
			if (arr[j] < arr[i] && (lis[j] + 1) > lis[i])
			{
				lis[i] = lis[j] + 1;
				array[i]++;
			}
		}
	}
	*count = max_elements(lis, n);
	return (array);
}
