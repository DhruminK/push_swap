/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:41:54 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/12 19:56:30 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_op.h"

void		ss(t_list **a, t_list **b, int op)
{
	if (op == 0)
	{
		ft_putendl("sb");
		swap(b);
	}
	else if (op == 1)
	{
		ft_putendl("sa");
		swap(a);
	}
	else if (op == 2)
	{
		ft_putendl("ss");
		swap(a);
		swap(b);
	}
}

void		rr(t_list **a, t_list **b, int op)
{
	if (op == 0)
	{
		ft_putendl("rb");
		rotate(b);
	}
	else if (op == 1)
	{
		ft_putendl("ra");
		rotate(a);
	}
	else if (op == 2)
	{
		ft_putendl("rr");
		rotate(a);
		rotate(b);
	}
}

void		rrr(t_list **a, t_list **b, int op)
{
	if (op == 0)
	{
		ft_putendl("rrb");
		rrotate(b);
	}
	else if (op == 1)
	{
		ft_putendl("rra");
		rrotate(a);
	}
	else if (op == 2)
	{
		ft_putendl("rrr");
		rrotate(a);
		rrotate(b);
	}
}

int			ps(t_list **a, t_list **b, int op)
{
	if (op == 0)
	{
		ft_putendl("pa");
		if (!push_stack(b, a))
			return (0);
	}
	else
	{
		ft_putendl("pb");
		if (!push_stack(a, b))
			return (0);
	}
	return (1);
}
