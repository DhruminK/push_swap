/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:25:12 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/14 15:28:48 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

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
			ps(a, b, 1);
		else if ((j = j + 1))
			rr(a, b, 1);
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

	if (len < 5)
		return (ft_sort_b_less(a, b, m, len));
	if (!(i = ft_find_median(*b, len, &num)))
		return (0);
	*m = num;
	i = 0;
	j = 0;
	k = 0;
	while (++i <= len && k < len / 2)
	{
		if (ft_lstcmp_num(*b, num) > 0 && (k = k + 1))
			ps(a, b, 0);
		else if ((j = j + 1))
			rr(a, b, 0);
	}
	return (1);
}
