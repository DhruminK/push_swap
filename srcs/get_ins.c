/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:54:45 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/29 20:40:01 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"

int				ft_find_ins(t_list **a, t_list **b, char *s)
{
	if (!ft_strcmp("pb", s))
		push_stack(a, b);
	else if(!ft_strcmp("pa", s))
		push_stack(b, a);
	else if (!ft_strcmp("ra", s))
		rotate(a);
	else if (!ft_strcmp("rb", s))
		rotate(b);
	else if (!ft_strcmp("rr", s))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp("rra", s))
		rrotate(a);
	else if (!ft_strcmp("rrb", s))
		rrotate(b);
	else if (!ft_strcmp("rrr", s))
	{
		rrotate(a);
		rrotate(b);
	}
	else if (!ft_strcmp("sa", s))
		swap(a);
	else if (!ft_strcmp("sb", s))
		swap(b);
	else
		return (0);
	return (1);
}

int				ft_get_ins(t_list **a, t_list **b)
{
	char		*line;
	int			ret;

	while ((ret = get_next_line(0, &line)) == 1)
	{
		if (!ft_find_ins(a, b, line) && ft_strdel(&line))
			return (0);
		ft_strdel(&line);
	}
	if (ret == 0)
		return (1);
	return (0);
}
