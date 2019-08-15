/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:55:57 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/15 19:16:40 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int			size_inc(int **arr, int data, int size)
{
	int			*new_arr;
	int			i;

	if (size < 0)
		return (0);
	if (!(new_arr = (int*)malloc(sizeof(int) * (size + 1))))
		return (-1);
	i = -1;
	while (++i < size)
		new_arr[i] = (*arr)[i];
	new_arr[i] = data;
	if (size != 0 && arr && *arr)
		ft_memdel((void**)arr);
	*arr = new_arr;
	return (1);
}

int			size_dec(int **arr, int *data, int size)
{
	int			*new_arr;
	int			i;

	new_arr = 0;
	i = 0;
	if (size < 1)
		return (0);
	if (size > 1)
	{
		if (!(new_arr = (int*)malloc(sizeof(int) * (size - 1))))
			return (-1);
		i = -1;
		while (++i < size - 1)
			new_arr[i] = (*arr)[i];
	}
	if (data)
		*data = (*arr)[i];
	ft_memdel((void**)arr);
	*arr = new_arr;
	return (1);
}

int			push(t_stack *stack, int data)
{
	if (!stack)
		return (-1);
	stack->head = stack->head + 1;
	if (size_inc(&(stack->data), data, stack->head) < 1)
		return (-1);
	return (1);
}

int			pop(t_stack *stack, int *data)
{
	if (!stack)
		return (-1);
	if (size_dec(&(stack->data), data, stack->head + 1) < 1)
		return (-1);
	stack->head = stack->head - 1;
	return (1);
}
