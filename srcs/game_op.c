/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:15:40 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/26 15:48:12 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_op.h"

void		swap_stack(t_list **a)
{
	t_list		*ele;
	t_list		*ele1;

	ele = *a;
	ele1 = ele->next;
	ele->next = ele1->next;
	ele1->next = ele;
	*a = ele1;
}

void		swap(t_list **a, int dir)
{
	if (a && dir)
	{
		swap_stack(a);
		ft_putendl("sa");
	}
	if (a && !dir)
	{
		ft_putendl("sb");
		swap_stack(a);
	}
}

int			push_stack(t_list **a, t_list **b)
{
	int			d;

	if (pop(a, &d) < 1)
		return (0);
	if (push(b, d) < 1)
		return (0);
	return (1);
}
