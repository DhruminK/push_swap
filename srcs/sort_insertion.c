/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:11:33 by dkhatri           #+#    #+#             */
/*   Updated: 2019/09/28 17:40:20 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int					ft_insertion_init_b(t_list **a, t_list **b, int *len)
{
	int				s;
	int				i;

	while (*len > 3)
	{
		ft_small(a, *len);
		if ((i = ft_is_sorted(*a, &s, 1)) && s == 1)
			break ;
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

static int			ft_deinit_b(t_list **a, t_list **b)
{
	while (*b)
	{
		if (!push_stack(b, a))
			return (0);
		ft_putendl("pa");
	}
	return (1);
}

int					ft_sort3(t_list **a)
{
	int			pos;
	int			i;
	int			s;

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
	return ((i = ft_is_sorted(*a, &s, 1)) && s ? 1 : ft_sort3(a));
}

int						ft_sort_less(t_list **a)
{
	int				len;
	int				i;
	int				s;

	if ((i = ft_is_sorted(*a, &s, 1)) && s)
		return (1);
	if (!i)
		return (0);
	len = ft_lstlen(*a);
	if (len == 3)
	{
		if (!ft_sort3(a))
			return (0);
	}
	else if (len == 2 && ft_lstcmp(*a, (*a)->next) > 0)
	{
		swap(a);
		ft_putendl("sa");
	}
	return (1);
}

int						ft_sort_insertion(t_list **a, t_list **b)
{
	int			len;

	len = ft_lstlen(*a);
	if (!ft_insertion_init_b(a, b, &len))
		return (0);
	if (!ft_sort_less(a))
		return (0);
	ft_deinit_b(a, b);
	return (1);
}
