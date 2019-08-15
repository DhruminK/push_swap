/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_op_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:24:55 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/15 19:18:51 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_op.h"

int			rcycle(int *arr, int size)
{
	int			le;
	int			i;
	int			tmp;
	int			tmp1;

	if (!arr || size < 2)
		return (0);
	i = 0;
	le = arr[size - 1];
	tmp = arr[0];
	while (i < size - 1)
	{
		tmp1 = arr[i + 1];
		arr[i + 1] = tmp;
		tmp = tmp1;
		i = i + 1;
	}
	arr[0] = le;
	return (1);
}

int			rrcycle(int *arr, int size)
{
	int			le;
	int			i;
	int			tmp;
	int			tmp1;

	if (!arr || size < 2)
		return (0);
	i = size - 1;
	le = arr[0];
	tmp = arr[size - 1];
	while (i > 0)
	{
		tmp1 = arr[i - 1];
		arr[i - 1] = tmp;
		tmp =  tmp1;
		i = i - 1;
	}
	arr[size - 1] = le;
	return (1);
}

int			rotate(t_stack *a)
{
	return (rcycle(a->data, a->head + 1));
}

int			rrotate(t_stack *a)
{
	return (rrcycle(a->data, a->head + 1));
}
