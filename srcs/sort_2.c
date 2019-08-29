/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:06:02 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/29 18:41:29 by dkhatri          ###   ########.fr       */
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
	int			ma;
	int			mb;

	ita = 0;
	itb = 0;
	ma = 0;
	mb = 0;
	resb = 1;
	len = ft_lstlen(*a);
	if (len > MAX_LEN && !ft_init_b(a, b))
		return (0);
	while ((resa = ft_single_sort(a, &ita, 1, &ma)) != 1 \
			|| (len > MAX_LEN && (resb = ft_single_sort(b, &itb, 0, &mb)) != 1))
	{
		if (resa == -1 || resb == -1)
			return (0);
		ft_rotate(a, b, resa, resb);
	}
	if (len > MAX_LEN && !ft_deinit_b(a, b))
		return (0);
	return (1);
}
