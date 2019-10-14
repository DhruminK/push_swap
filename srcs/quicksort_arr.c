/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:21:06 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/14 15:45:00 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int			ft_conv_arr(t_list *a, int *arr, int len)
{
	int				i;

	i = -1;
	if (!a || !arr || !len)
		return (0);
	while (++i < len && a)
	{
		arr[i] = ft_lstdata(a);
		a = a->next;
	}
	if (len != i)
		return (0);
	return (1);
}

int					partition(int *arr, int start, int end)
{
	int			piv;
	int			tmp;
	int			i;
	int			j;

	piv = arr[start];
	i = start + 1;
	j = end;
	while (i <= j)
	{
		if (arr[i] < piv)
			i++;
		if (arr[j] >= piv)
			j--;
		if (i < j && arr[j] < piv && arr[i] >= piv)
		{
			tmp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = tmp;
		}
	}
	arr[start] = arr[j];
	arr[j] = piv;
	return (j);
}

void				quicksort(int *arr, int start, int end)
{
	int				j;

	if (start >= end)
		return ;
	j = partition(arr, start, end);
	quicksort(arr, start, j - 1);
	quicksort(arr, j + 1, end);
}

int					ft_find_median(t_list *a, int len, int *m)
{
	int				arr[len];

	if (len < 1 || !a || !m || !(ft_conv_arr(a, arr, len)))
		return (0);
	quicksort(arr, 0, len - 1);
	*m = arr[len % 2 == 0 ? len / 2 : (((len + 1) / 2) - 1)];
	return (1);
}
