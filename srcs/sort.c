/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:16:14 by dkhatri           #+#    #+#             */
/*   Updated: 2019/08/17 20:53:33 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int			ft_lstcmp(t_list *a, t_list *b)
{
	return ((*((int*)a->content)) - (*((int*)b->content)));
}

int			ft_is_sorted(t_list *a, int *s)
{
	t_list		*ele;

	if (!a || !s)
		return (-1);
	ele = a->next;
	if (ft_lstcmp(a, ele) > 0 && !(*s = 0))
		return (0);
	ele = ele->next;
	a = a->next;
	while (ele)
	{
		if (ft_lstcmp(a, ele) > 0)
		{
			*s = 1;
			if (ele->next == 0 && (*s = 2))
				return (0);
			else
				return (0);
		}
		ele = ele->next;
		a = a->next;
	}
	return (1);
}

void		ft_print_stack(t_list *a)
{
	ft_putendl("++++++++++++");
	while (a)
	{
		ft_putnbr(*((int*)(a->content)));
		ft_putendl("");
		a = a->next;
	}
	ft_putendl("++++++++++++\n");
}

int			ft_sort(t_list **a, t_list **b, int it, int d)
{
	int			s;
	int			i;

/*	if (d == 0)
		return (1);
*/	if ((i = ft_is_sorted(*a, &s)) < 0)
		return (-1);
	if (s == 0)
	{
		swap(a, 0);
		while (it > 0)
		{
			ft_putendl("rra");
			rrotate(a);
			it = it - 1;
			if (ft_lstcmp(*a, (*a)->next) > 0)
				swap(a, 0);
		}
	}
	else if (s == 2)
	{
		ft_putendl("rra");
		rrotate(a);
	}
	else
	{
		ft_putendl("ra");
		it = it + 1;
		rotate(a);
	}
//	ft_print_stack(*a);
	return ((i = ft_is_sorted(*a, &s)) == 1 ? 1 : ft_sort(a, b, it, --d));
}
