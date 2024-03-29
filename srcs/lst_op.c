/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:11:33 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/14 15:39:13 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_op.h"

int			ft_lstlen(t_list *a)
{
	int		len;

	len = 0;
	while (a)
	{
		a = a->next;
		len = len + 1;
	}
	return (len);
}

int			ft_lstcmp(t_list *a, t_list *b)
{
	return ((*((int*)(a->content))) - (*((int*)(b->content))));
}

int			ft_lstdata(t_list *a)
{
	return (*((int*)(a->content)));
}

int			ft_lstcmp_num(t_list *a, int num)
{
	return (ft_lstdata(a) - (num));
}

int			ft_ra_rra(t_list *head, t_list *ele, int *op)
{
	t_list			*e;
	int				ra;
	int				rra;

	if (!head || !ele)
		return (0);
	e = head;
	ra = 0;
	while (e && e != ele && (ra = ra + 1))
		e = e->next;
	if (!e)
		return (0);
	rra = 0;
	while (e && (rra = rra + 1))
		e = e->next;
	rra = rra + 1;
	*op = 1;
	if (rra < ra)
		*op = 0;
	return (1);
}
