/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:54:10 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/11 17:34:57 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int			ft_findmin(t_list *a, int *min)
{
	t_list		*m;
	int			l;
	int			ele;

	if (!a)
		return (0);
	m = a;
	l = 1;
	ele = 1;
	a = a->next;
	while (a && ++l)
	{
		if (ft_lstcmp(m, a) > 0 && (ele = l))
			m = a;
		a = a->next;
	}
	if (min)
		*min = ft_lstdata(m);
	return (ele);
}

int			ft_findmax(t_list *a, int *max)
{
	t_list		*m;
	int			l;
	int			ele;

	if (!a)
		return (0);
	m = a;
	l = 1;
	ele = 1;
	a = a->next;
	while (a && ++l)
	{
		if (ft_lstcmp(m, a) < 0 && (ele = l))
			m = a;
		a = a->next;
	}
	if (max)
		*max = ft_lstdata(m);
	return (ele);
}

void		ft_small(t_list **a, int len)
{
	int				pos;
	int				min;
	int				dir;

	dir = 0;
	pos = ft_findmin(*a, &min);
	if (len - pos + 1 < pos - 1)
		dir = 1;
	pos = dir ? len - pos + 1 : pos - 1;
	while (pos--)
	{
		if (dir)
		{
			ft_putendl("rra");
			rrotate(a);
		}
		else
		{
			ft_putendl("ra");
			rotate(a);
		}
	}
}

int			ft_half_sort_insertion(t_list **a, t_list **b)
{
	int			len;
	int			i;
	int			s;

	len = ft_lstlen(*a);
	if (!ft_insertion_init_b(a, b, &len))
		return (0);
	if ((i = ft_is_sorted(*a, &s, 1, -1)) && !s)
		i = ft_sort_less(a);
	if (!i)
		return (0);
	return (1);
}
