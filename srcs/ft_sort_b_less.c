/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b_less.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:09:28 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/14 15:15:13 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int			ft_sort3_b(t_list **a, t_list **b, int *m)
{
	int			pos;

	if (!(pos = ft_findmax(*b, 0)))
		return (0);
	if (pos == 1)
		ps(a, b, 0);
	else if (pos == 2)
		rr(a, b, 0);
	else if (pos == 3)
		rrr(a, b, 0);
	if (!*b)
	{
		*m = ft_lstdata(*a);
		return (1);
	}
	return (ft_sort3_b(a, b, m));
}

int			ft_sort4_b(t_list **a, t_list **b, int *m)
{
	int			pos;

	if (!(pos = ft_findmax(*b, 0)))
		return (0);
	if (pos == 1)
	{
		ps(a, b, 0);
		return (ft_sort3_b(a, b, m));
	}
	else if (pos == 4)
		rrr(a, b, 0);
	else
		rr(a, b, 0);
	return (ft_sort4_b(a, b, m));
}

int			ft_sort2_b(t_list **a, t_list **b, int *m, int len)
{
	if (len == 2 && ft_lstcmp(*b, (*b)->next) < 0)
		ss(a, b, 0);
	while (len-- > 0)
		ps(a, b, 0);
	*m = ft_lstdata(*a);
	return (1);
}

int			ft_sort_b_less(t_list **a, t_list **b, int *m, int len)
{
	if (len < 3)
		return (ft_sort2_b(a, b, m, len));
	else if (len == 3)
		return (ft_sort3_b(a, b, m));
	else if (len == 4)
		return (ft_sort4_b(a, b, m));
	return (1);
}
