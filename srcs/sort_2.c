/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:06:02 by dkhatri           #+#    #+#             */
/*   Updated: 2019/09/19 14:41:31 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static int				ft_init_b(t_list **a, t_list **b)
{
	int			len;
	int			j;
	int			i;
	int			m;

	len = ft_lstlen(*a);
	if (!ft_find_median(*a, len, &m))
		return (0);
	i = -1;
	j = 0;
	while (++i < len - 1 && j < len / 2)
	{
		if ((*((int*)((*a)->content))) < m && (j = j + 1))
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

/*void			ft_rotate(t_list **a, t_list **b, int resa, int resb)
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
}*/

static int				ft_deinit_b(t_list **a, t_list **b)
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

/*int				ft_sort(t_list **a, t_list **b)
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
}*/

void			ft_rotate(t_list **a, t_list **b, int ret_a, int ret_b)
{
	if (ret_a == 3 && ret_b == 3)
	{
		ft_putendl("rr");
		rotate(a);
		rotate(b);
		return ;
	}
	else if (ret_a == 2 && ret_b == 2)
	{
		ft_putendl("ss");
		swap(a);
		swap(b);
		return ;
	}
	if (ret_a == 2)
	{
		ft_putendl("sa");
		swap(a);
	}
	if (ret_b == 2)
	{
		ft_putendl("sb");
		swap(b);
	}
	if (ret_a == 3)
	{
		ft_putendl("ra");
		rotate(a);
	}
	if (ret_b == 3)
	{
		ft_putendl("rb");
		rotate(b);
	}
}

int				ft_sort(t_list **a, t_list **b)
{
	int			len;
	int			var_a[3];
	int			var_b[3];

	len = ft_lstlen(*a);
	var_a[0] = 0;
	var_b[0] = 0;
	if (len > MAX_LEN && !ft_init_b(a, b))
		return (0);
	var_a[2] = ft_lstlen(*a);
	var_b[2] = ft_lstlen(*b);
	while (1)
	{
		var_a[1] = ft_sort_bubble_opti(a, &(var_a[0]), var_a[2], 1);
		if (len > MAX_LEN)
			var_b[1] = ft_sort_bubble_opti(b, &(var_b[0]), var_b[2], 0);
		if (var_a[1] == 1 && ((len > MAX_LEN && var_b[1] == 1) || len <= MAX_LEN))
			break;
		ft_rotate(a, b, var_a[1], var_b[1]);
	}
	if (len > MAX_LEN && !ft_deinit_b(a, b))
		return (0);
	return (1);
}
