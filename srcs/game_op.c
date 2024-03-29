/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 18:15:40 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/29 20:38:39 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_op.h"

void		swap(t_list **a)
{
	t_list		*ele;
	t_list		*ele1;

	ele = *a;
	ele1 = ele->next;
	ele->next = ele1->next;
	ele1->next = ele;
	*a = ele1;
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
