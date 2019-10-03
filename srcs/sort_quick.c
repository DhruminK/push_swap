/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:28:51 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/03 21:28:53 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void			ft_rra(t_list **a, int len)
{
	int			i;

	i = 0;
	while (++i <= len)
	{
		ft_putendl("rra");
		rrotate(a);
	}
}

int				ft_push_b(t_list **a, t_list **b, int len, int *m)
{
	int			num;
	int			is_sorted;
	int			i;
	int			j;
	int			k;

	if (len < 3)
		return (1);
	is_sorted = len != ft_lstlen(*a) ? 1 : 0;
	if (!(i = ft_find_median(*a, len, &num)))
		return (0);
	*m = num;
	j = 0;
	i = 0;
	k = 0;
	while (++i <= len && k < len / 2)
	{
		if (ft_lstcmp_num(*a, num) < 0 && (k = k + 1))
		{
			ft_putendl("pb");
			push_stack(a, b);
		}
		else if((j = j + 1))
		{
			ft_putendl("ra");
			rotate(a);
		}
	}
	if (is_sorted)
		ft_rra(a, j);
	return (1);
}

int				ft_sort_quick_2(t_list **a, int len)
{
	if(len == 2 && ft_lstcmp(*a, (*a)->next) > 0)
	{
		ft_putendl("sa");
		swap(a);
		return (1);
	}
	else if (len == 3)
		return (ft_sort3(a));
	return (1);
}

int				ft_init_b(t_list **a, t_list **b, t_list **piv, int len)
{
	int			len_a;
	int			len_b;
	int			tmp;
	int			i;
	int			j;

	len_a = len == 0 ? ft_lstlen(*a) : len;
	j = len == 0 ? 3 : 2;
	len_b = len == 0 ? 0 : ft_lstlen(*b);
	i = 0;
	while (len_a > j && (ft_is_sorted(*a, &i, 1) && !i))
	{
		if (!ft_push_b(a, b, len_a, &i))
			return (0);
		tmp = ft_lstlen(*b);
		tmp = tmp - len_b;
		len_a = len_a - tmp;
		len_b = len_b + tmp;
		push(piv, i);
	}
	if (!ft_sort_quick_2(a, len_a))
		return (0);
	return (1);
}

int				ft_deinit_b(t_list **a, t_list **b, t_list **piv)
{
	int			data;
	int			i;

	while (*b)
	{
		pop(piv, &data);
		top(piv, &data);
		i = 0;
		while ((*b && ft_lstcmp_num(*b, data) >= 0) || (*b && !*piv))
		{
			i = i + 1;
			ft_putendl("pa");
			push_stack(b, a);
		}
		if (!ft_init_b(a, b, piv, i))
			return (0);
	}
	return (1);
}

int				ft_sort_quick(t_list **a, t_list **b)
{
	t_list		*piv;

	piv = 0;
	if (!ft_init_b(a, b, &piv, 0))
		return (0);
	if (!ft_deinit_b(a, b, &piv))
		return (0);
	return (1);
}
