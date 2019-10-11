/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:48:35 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/11 19:47:01 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void		ft_rra(t_list **a, int len, char *op)
{
	int			i;

	i = 0;
	while (++i <= len)
	{
		ft_putendl(op);
		rrotate(a);
	}
}

int			ft_push_b(t_list **a, t_list **b, int len, int *m)
{
	int			num;
	int			i;
	int			j;
	int			k;
	int			is_sorted;

	if (!(j = 0) && len < 3)
		return (1);
	if (!(i = ft_find_median(*a, len, &num)))
		return (0);
	k = 0;
	i = 0;
	*m = num;
	is_sorted = len == ft_lstlen(*a) ? 0 : 1;
	while (++i <= len && k < len / 2)
	{
		if (ft_lstcmp_num(*a, num) < 0 && (k = k + 1))
		{
			ft_putendl("pb");
			push_stack(a, b);
		}
		else if ((j = j + 1))
		{
			ft_putendl("ra");
			rotate(a);
		}
	}
	if (is_sorted)
		ft_rra(a, j, "rra");
	return (1);
}

int			ft_push_a(t_list **a, t_list **b, int len, int *m)
{
	int			num;
	int			i;
	int			j;
	int			k;

	if (len == 2 && ft_lstcmp(*b, (*b)->next) < 0)
	{
		ft_putendl("sb");
		swap(b);
	}
	if (len < 3)
	{
		while (len-- > 0)
		{
			ft_putendl("pa");
			push_stack(b, a);
		}
		*m = ft_lstdata(*a);
		return (1);
	}
	if (!(i = ft_find_median(*b, len, &num)))
		return (0);
	*m = num;
	i = 0;
	j = 0;
	k = 0;
	while (++i <= len && k < len / 2)
	{
		if (ft_lstcmp_num(*b, num) > 0 && (k = k + 1))
		{
			ft_putendl("pa");
			push_stack(b, a);
		}
		else if ((j = j + 1))
		{
			ft_putendl("rb");
			rotate(b);
		}
	}
	return (1);
}

int			ft_find_num(t_list *a, int n1, int *n2)
{
	int			len;
	int			num;

	if (!a)
		return (0);
	num = ft_lstdata(a);
	len = 0;
	while (a && n1 <= num && ((n2 && *n2 >= num) || !n2))
	{
		len = len + 1;
		a = a->next;
		if (a)
			num = ft_lstdata(a);
	}
	return (len);
}

int			ft_deinit_b(t_list **a, t_list **b, t_list **piv)
{
	int			num;
	int			len_a;
	int			len_b;
	int			tmp;

	len_a = ft_lstlen(*a);
	len_b = ft_lstlen(*b);
	while (*b)
	{
		if (!ft_push_a(a, b, len_b, &num))
			return (0);
		tmp = ft_lstlen(*a);
		tmp = tmp - len_a;
		len_b = len_b - tmp;
		len_a = len_a + tmp;
		push(piv, num);
	}
	return (1);
}

int			ft_deinit_piv(t_list **a, t_list **b, t_list **piv)
{
	int		t1;
	int		t0;
	int		s;
	int		i;
	int		tmp1;

	while (*piv)
	{
		pop(piv, &t0);
		top(piv, &t1);
		i = ft_find_num(*a, t0 , *piv ? &t1 : 0);
		if (i == 2 && ft_lstcmp(*a, (*a)->next) > 0)
		{
			ft_putendl("sa");
			swap(a);
		}
		else if (i > 2 && ft_is_sorted(*a, &s, 1, i) && !s)
		{
			if (!ft_push_b(a, b, i, &tmp1))
				return (0);
			push(piv, tmp1);
			if (!ft_deinit_b(a, b, piv))
				return (0);
		}
		if (i < 3 || (i > 2 && s))
		{
			while (i-- > 0)
			{
				ft_putendl("ra");
				rotate(a);
			}
		}
	}
	return (1);
}

int			ft_sort_quick(t_list **a, t_list **b)
{
	t_list		*piv;
	int			len;
	int			num;

	piv = 0;
	len = ft_lstlen(*a);
	if (!ft_push_b(a, b, len, &num))
		return (0);
	push(&piv, num);
	if (!ft_deinit_b(a, b, &piv))
		return (0);
	if (!ft_deinit_piv(a, b, &piv))
		return (0);
	return (1);
}
