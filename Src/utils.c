/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:51:30 by fgrossi           #+#    #+#             */
/*   Updated: 2022/04/29 13:21:47 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/swap.h"

int	count_args(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	unsigned long	i;
	const char		*temp;

	i = 0;
	temp = s;
	while (*temp)
	{
		i++;
		temp++;
	}
	return (i);
}

int	ft_putstr(char *str)
{
	char	c;
	int		i;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		c = str[i];
		write (1, &c, 1);
		i++;
	}
	if (i != 0)
		return (0);
	else
		return (1);
}

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->cnt = content;
	list->next = 0;
	return (list);
}

t_list	*ft_lstnew_char(char *str)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->str_temp = str;
	list->next = 0;
	return (list);
}
