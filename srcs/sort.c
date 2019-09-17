/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:54:10 by dkhatri           #+#    #+#             */
/*   Updated: 2019/09/17 19:49:47 by dkhatri          ###   ########.fr       */
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

int			ft_init_b(t_list **a, t_list **b, int *len)
{
	int			s;
	int			i;

	while (*len > 3)
	{
		ft_small(a, *len);
		if ((i = ft_is_sorted(*a, &s)) && s == 1)
			break;
		else if (i == 0)
			return (0);
		else
		{
			ft_putendl("pb");
			push_stack(a, b);
			*len = *len - 1;
		}
	}
	return (1);
}

int			ft_sort3(t_list **a, int d)
{
	int			pos;
	int			i;
	int			s;

	if (d == 0)
		return (1);
	if (!(pos = ft_findmax(*a, 0)))
		return (0);
	if (pos == 1)
	{
		ft_putendl("ra");
		rotate(a);
	}
	else if (pos == 2 || (pos = ft_findmin(*a, 0)) == 3)
	{
		ft_putendl("rra");
		rrotate(a);
	}
	else if (pos == 2)
	{
		ft_putendl("sa");
		swap(a);
	}
	return ((i = ft_is_sorted(*a, &s)) && s ? 1 : ft_sort3(a, --d));
}

void		ft_deinit_b(t_list **a, t_list **b)
{
	while (push_stack(b, a) == 1)
		ft_putendl("pa");
}

int			ft_sort(t_list **a, t_list **b)
{
	int			len;

	len = ft_lstlen(*a);
	if (!ft_init_b(a, b, &len))
		return (0);
	if (len == 3)
	{
		if (!ft_sort3(a, 10))
			return (0);
	}
	else if (len == 2 && ft_lstcmp(*a, (*a)->next) > 0)
	{
		swap(a);
		ft_putendl("sa");
	}
	ft_deinit_b(a, b);
	return (1);
}
