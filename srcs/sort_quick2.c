/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:48:35 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/14 17:29:14 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

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

int			ft_sort_piv(t_list **a, t_list **b, t_list **piv, int i)
{
	int			tmp1;

	if (!ft_push_b(a, b, i, &tmp1))
		return (0);
	push(piv, tmp1);
	if (!ft_deinit_b(a, b, piv))
		return (0);
	return (1);
}

int			ft_deinit_piv(t_list **a, t_list **b, t_list **piv)
{
	int		t1;
	int		t0;
	int		s;
	int		i;

	while (*piv)
	{
		pop(piv, &t0);
		top(piv, &t1);
		i = ft_find_num(*a, t0, *piv ? &t1 : 0);
		if (i == 2 && ft_lstcmp(*a, (*a)->next) > 0)
			ss(a, b, 1);
		else if (i > 2 && ft_is_sorted(*a, &s, 1, i) && !s)
		{
			if (!ft_sort_piv(a, b, piv, i))
				return (0);
		}
		if (i < 3 || (i > 2 && s))
		{
			while (i-- > 0)
				rr(a, b, 1);
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
	if (!ft_is_sorted(*a, &len, 1, -1))
		return (0);
	if (len == 1)
		return (1);
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
