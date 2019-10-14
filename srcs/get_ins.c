/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:54:45 by dkhatri           #+#    #+#             */
/*   Updated: 2019/10/14 16:07:45 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instruction.h"
#include "sort.h"

int				ft_find_ins2(t_list **a, t_list **b, char *s)
{
	if (!ft_strcmp("rr", s))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strcmp("rrr", s))
	{
		rrotate(a);
		rrotate(b);
	}
	else if (!ft_strcmp("ss", s))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strcmp("ra", s))
		rotate(a);
	else if (!ft_strcmp("rb", s))
		rotate(b);
	else
		return (0);
	return (1);
}

int				ft_find_ins(t_list **a, t_list **b, char *s)
{
	if (!s)
		return (1);
	if (!ft_strcmp("pb", s))
	{
		if (!push_stack(a, b))
			return (0);
	}
	else if (!ft_strcmp("pa", s))
	{
		if (!push_stack(b, a))
			return (0);
	}
	else if (!ft_strcmp("rra", s))
		rrotate(a);
	else if (!ft_strcmp("rrb", s))
		rrotate(b);
	else if (!ft_strcmp("sa", s))
		swap(a);
	else if (!ft_strcmp("sb", s))
		swap(b);
	else if (ft_find_ins2(a, b, s))
		return (1);
	else
		return (0);
	return (1);
}

static int		empty_line(char **line)
{
	char		*l;
	int			ret;

	ft_strdel(line);
	while ((ret = get_next_line(0, &l)) == 1)
		ft_strdel(&l);
	return (1);
}

int				ft_get_ins(t_list **a, t_list **b)
{
	char		*line;
	int			ret;

	line = 0;
	while (((ret = get_next_line(0, &line)) == 1))
	{
		if (!ft_find_ins(a, b, line) && empty_line(&line))
			return (0);
		ft_strdel(&line);
	}
	if (ret == 0 && !line)
		return (1);
	if (line)
		ft_strdel(&line);
	return (0);
}
