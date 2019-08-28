/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:06:02 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/28 18:06:02 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void			ft_print_stack(t_list *a)
{
	ft_putendl("++++++++++++++++++");
	while (a)
	{
		ft_putnbr(*((int*)(a->content)));
		ft_putendl("");
		a = a->next;
	}
	ft_putendl("++++++++++++++++++");
}

int				ft_single_sort(t_list **a, int *it, int dir)
{
	int				i;
	int				s;
	int				len;
	int				max;

	len = ft_lstlen(*a);
	if (!a && !*a)
		return (1);
	if ((i = ft_is_sorted(*a, &s, dir)))
		return (i);
	if (!(i = ft_lstmax(*a, &max, 0)))
		return (-1);
	if ((*(int*)((*a)->content)) == max && !(it = 0))
		return (2);
	else if (s == 2)
		return (3);
	else if (s == 0)
	{
		swap(a, dir);
		if (*it > 0)
		{
			*it = *it - 1;
			return (3);
		}
	}
	else if (s == 1 && (*it = *it + 1))
		return (2);
	else if (*it > 0)
	{
		*it = *it - 1;
		return (3);
	}
	return (ft_single_sort(a, it, dir));
}

int				ft_init_b(t_list **a, t_list **b)
{
	int			len;
	int			i;
	int			m;

	len = ft_lstlen(*a);
	if (!ft_find_median(*a, len, &m))
		return (0);
	i = -1;
	while (++i < len - 1)
	{
		if ((*((int*)((*a)->content))) < m)
		{
			ft_putendl("pb");
			if (!(push_stack(a, b)))
				return (0);
		}
		else
		{
			ft_putendl("ra");
			rotate(a);
		}
	}
	if ((*((int*)((*a)->content))) < m)
	{
		ft_putendl("pb");
		if (!(push_stack(a, b)))
			return (0);
	}
	return (1);
}

void			ft_rotate(t_list **a, t_list **b, int resa, int resb)
{
	if (a && b && resa == 2 && resb == 2)
	{
		ft_putendl("rr");
		rotate(a);
		rotate(b);
		return ;
	}
	else if (a && b && resa == 3 && resb == 3)
	{
		ft_putendl("rrr");
		rrotate(a);
		rrotate(b);
		return ;
	}
	if (a && resa == 2)
	{
		ft_putendl("ra");
		rotate(a);
	}
	if (b && resb == 2)
	{
		ft_putendl("rb");
		rotate(b);
	}
	if (a && resa == 3)
	{
		ft_putendl("rra");
		rrotate(a);
	}
	if (b && resb == 3)
	{
		ft_putendl("rrb");
		rrotate(b);
	}
}

int				ft_deinit_b(t_list **a, t_list **b)
{
	int			len;

	len = ft_lstlen(*b);
	while (len-- > 0)
	{
		ft_putendl("pa");
		if (!(push_stack(b, a)))
			return (0);
	}
	return (1);
}

int				ft_sort(t_list **a, t_list **b)
{
	int			ita;
	int			itb;
	int			resa;
	int			resb;
	int			len;

	ita = 0;
	itb = 0;
	resb = 1;
	len = ft_lstlen(*a);
	if (len > 4 && !ft_init_b(a, b))
		return (0);
	while ((resa = ft_single_sort(a, &ita, 1)) != 1 \
			|| (len > 4 && (resb = ft_single_sort(b, &itb, 0)) != 1))
	{
		if (resa == -1 || resb == -1)
			return (0);
		ft_rotate(a, b, resa, resb);
	}
	if (len > 4 && !ft_deinit_b(a, b))
		return (0);
	return (1);
}
