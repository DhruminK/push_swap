/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:15:40 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/15 19:18:45 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_op.h"

void		swap_stack(t_stack *a)
{
	int			tmp;

	if (a->head < 1)
		return ;
	tmp = a->data[a->head];
	a->data[a->head] = a->data[a->head - 1];
	a->data[a->head - 1] = tmp;
}

void		swap(t_stack *a, t_stack *b)
{
	if (a)
		swap_stack(a);
	if (b)
		swap_stack(b);
}

int			push_stack(t_stack *a, t_stack *b)
{
	int			d;

	if (pop(a, &d) < 1)
		return (0);
	if (push(b, d) < 1)
		return (0);
	return (1);
}
